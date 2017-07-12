#ifndef PURECPROGRAM_H
#define PURECPROGRAM_H

#include <thread>
#include <string>
#include <mutex>
#include <list>
#include <myqueue.h>
#include <mythread.h>
#include <message.h>
#include <QDebug>
class PureCProgram:public myThread
{
    MyQueue<Message*>& _queue;
public:
    PureCProgram(MyQueue<Message*>& queue):_queue(queue){}
    void *run()
    {
        for(int i=0;i<100;i++)
        {
            qDebug()<<"Adding Item"<<QString::number(i);
            Message* item = new Message(std::to_string(i).c_str());
            _queue.add(item);
            delete item;
        }
        return NULL;
    }
};

#endif // PURECPROGRAM_H
