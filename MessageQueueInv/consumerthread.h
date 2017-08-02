#ifndef CONSUMERTHREAD_H
#define CONSUMERTHREAD_H
#include <thread.h>
#include <workitem.h>
#include <wqueue.h>
//#include <QDebug>
#include <string>
#include <youralgorithm.h>
class ConsumerThread:public Thread
{
    wqueue<WorkItem> &Myqueue;
    int _ID;
public:
    ConsumerThread(wqueue<WorkItem>& queue,int id):Myqueue(queue),_ID(id){}
    void* run()
    {
        int myParam = 10;
        if(_ID == 1)
        {
            yourAlgorithm algorithm(myParam,Myqueue);
            algorithm.Start();
        }
        else if(_ID == 2)
        {
            yourAlgorithmB<ConsumerThread> algorithmB(myParam,this,&ConsumerThread::addItem);
            algorithmB.Start();
        }
        return NULL;
    }

    void addItem(WorkItem a)
    {
        Myqueue.add(a);
    }
};

#endif // CONSUMERTHREAD_H
