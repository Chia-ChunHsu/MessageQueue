#ifndef YOURALGORITHM_H
#define YOURALGORITHM_H
// Alogirthm using queue, queue is it's private member
#include <wqueue.h>
#include <workitem.h>
#include <thread>
//Algorithm Type: Add queue in your Algorithm
class yourAlgorithm
{
private:
    wqueue<WorkItem> &_queue;
    int _param;
public:
    yourAlgorithm(int param,wqueue<WorkItem> &queue):_param(param),_queue(queue){
    }
    void Start()
    {
        for(int i=0;i<=1000000;i++)
        {
            //Sleep(1);
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
            std::string message= std::to_string(i);
            WorkItem a(message.c_str(),i/10000);
            _queue.add(a);
        }
    }
};

//Algorithm Type: Using function pointer to Call Adding queue Algorithm
template <typename T>
class yourAlgorithmB
{
private:
    typedef void (T::*call)(WorkItem);
    int _param;
    T* _tObject;
    const call _CB;
public:
    yourAlgorithmB<T>(int param,T* object,call CB):_param(param),_tObject(object),_CB(CB){}
    void Start()
    {
        for(int i=0;i<=1000000;i++)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
            std::string message= std::to_string(i);
            WorkItem a(message.c_str(),i/10000);
            (_tObject->*_CB)(a);
        }
    }
};

#endif // YOURALGORITHM_H
