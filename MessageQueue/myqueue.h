#ifndef MYQUEUE_H
#define MYQUEUE_H
#include <thread>
#include <mutex>
#include <condition_variable>
#include <list>
#include <message.h>

template <typename T>class MyQueue
{
    std::list<T> _queue;
    std::mutex   _mutex;
    std::condition_variable _condVar;
public:
    MyQueue(){
//        _mutex = NULL;
//        _condVar = NULL;
    }
    ~MyQueue()
    {
        _mutex.unlock();
        _condVar.notify_all();
    }
    void add(T item)
    {
        _mutex.lock();
        _queue.push_back(item);
        _condVar.notify_one();
        _mutex.unlock();
    }

    T remove()
    {
        _mutex.lock();
        while(_queue.size()==0)//pthread_cond_wait(&m_condv, &m_mutex);
        {
            std::unique_lock<std::mutex> lock(_mutex);
            _condVar.wait(lock);
        }
        T item = _queue.front();
        _queue.pop_front();
        _mutex.unlock();
        return item;
    }
    int size()
    {
        _mutex.lock();
        int size = _queue.size();
        _mutex.unlock();
        return size;
    }
};

#endif // MYQUEUE_H
