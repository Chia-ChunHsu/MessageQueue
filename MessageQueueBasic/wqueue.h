#ifndef WQUEUE_H
#define WQUEUE_H
#include <thread>
#include <list>
#include <mutex>
#include <condition_variable>
#include <QDebug>

template <class T> class wqueue
{
    std::list<T>   m_queue;
    std::mutex* m_mutex = 0;
    std::condition_variable* m_condv = 0;

public:
    wqueue() {
        m_mutex = new std::mutex();
        m_condv = new std::condition_variable();
//        m_mutex.unlock();
//        m_condv.notify_all();
    }
    ~wqueue() {   
        if(m_mutex)
        {
            m_mutex->lock();
            m_mutex->unlock();
            delete m_mutex;
        }
        if(m_condv)
        {
//            m_condv->notify_all();
            delete m_condv;
        }
    }
    void add(T item) {
        std::lock_guard<std::mutex> mLock(*m_mutex);
        //m_mutex.lock();
        m_queue.push_back(item);
        m_condv->notify_one();
        //m_mutex.unlock();
    }
    T remove() {
        //std::lock_guard<std::mutex> mLock(m_mutex);
       // m_mutex.lock();
//        qDebug()<<m_queue.size();
//        while(m_queue.size()==0)
//        {

        while(size() == 0) // Wait until have Item on the List
        {
           std::unique_lock<std::mutex> lk(*m_mutex);
           m_condv->wait(lk);

           lk.unlock();
        }
//        }
        std::lock_guard<std::mutex> mLock(*m_mutex);

        T item;

        item = m_queue.front();
        m_queue.pop_front();

        return item;
    }
    int size() {
        std::lock_guard<std::mutex> mLock(*m_mutex);
        //m_mutex.lock();
        int size = m_queue.size();
        //m_mutex.unlock();
        return size;
    }
};
#endif // WQUEUE_H
