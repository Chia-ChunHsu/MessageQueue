#ifndef PURECPROGRAM_H
#define PURECPROGRAM_H

#include <thread>
#include <string>
#include <mutex>
#include <list>
#include <myqueue.h>
#include <mythread.h>
#include <message.h>
class PureCProgram:public myThread
{
    MyQueue<Message*>& _queue;
public:
    PureCProgram(MyQueue<Message*>& queue):_queue(queue){}
//    void run();
//protected:
    void *run();
};

#endif // PURECPROGRAM_H
