#ifndef THREAD_H
#define THREAD_H

#include <thread>
class Thread
{
public:
    Thread();
    virtual ~Thread();

    bool start();
    bool join();
    bool detach();

    virtual void* run() = 0;
private:
    std::thread *myThread = 0;
    int _tID;
    bool _isRunning;
    bool _isDetached;
};

#endif // THREAD_H
