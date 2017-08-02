#ifndef UPDATEMANAGER_H
#define UPDATEMANAGER_H

#include <thread.h>
#include <workitem.h>
#include <wqueue.h>
//#include <QDebug>
#include <string>

#include <consumerthread.h>

template <typename T>
class UpdateManager: public Thread
{

private:
    typedef void (T::*call)(WorkItem);
    wqueue<WorkItem> &Myqueue;
    int _ID;
    const call _CALL;
    T* _Object;
    ConsumerThread* thread1;

public:
    UpdateManager<T>(wqueue<WorkItem>& queue,int id,T* tObject,call _CB = NULL):Myqueue(queue),_ID(id),_Object(tObject),_CALL(_CB){
    }

    void* run()
    {
        thread1 = new ConsumerThread(Myqueue, _ID);

        thread1->start();
        while(1)
        {

            WorkItem item = Myqueue.remove();
            //_ItemNum = item;
            (_Object->*_CALL)(item);
        }
        return NULL;
    }

};

#endif // UPDATEMANAGER_H
