#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <thread>
class myThread
{
public:
    myThread();
    virtual ~myThread();

    void start();
    void join();
    void detach();
    std::thread *self();

    virtual void* run() =0;
private:
    std::thread* _ThreadId = 0;
    bool _isRunning;
    bool _isDetached;
};

#endif // MYTHREAD_H
