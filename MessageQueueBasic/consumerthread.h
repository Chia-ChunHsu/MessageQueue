#ifndef CONSUMERTHREAD_H
#define CONSUMERTHREAD_H
#include <thread.h>
#include <workitem.h>
#include <wqueue.h>
#include <QDebug>
#include <string>
class ConsumerThread:public Thread
{
    wqueue<WorkItem> &Myqueue;
    int _ID;
public:
    ConsumerThread(wqueue<WorkItem>& queue,int id):Myqueue(queue),_ID(id){}
    void* run()
    {
        int time =0;
        while(1)
        {
            qDebug()<<"I am Thread "<<_ID<<" Loop: "<<time;
            WorkItem item = Myqueue.remove();
            std::string s(item.getMessage());

            int num = static_cast<int>(item.getNumber());
            qDebug()<<"Item is "/*<<item->getMessage()<<" "*/<<num;

            time++;
        }
        return NULL;
    }
};

#endif // CONSUMERTHREAD_H
