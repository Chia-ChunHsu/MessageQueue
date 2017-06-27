#include "mythread.h"

//static void* runThread(void* arg)
//{
//    return ((Thread*)arg)->run();
//}

myThread::myThread():_ThreadId(0),_isRunning(false),_isDetached(false)
{

}

myThread::~myThread()
{
    if(_isRunning == true && _isDetached == false)
        _ThreadId->detach();
    //!!!!!!
    if(_isRunning)
        _ThreadId->join();
}

void myThread::start()
{
    _ThreadId = new std::thread;
    if(_ThreadId)
        _isRunning = true;
}

void myThread::join()
{
    if(_isRunning)
    {
        _ThreadId->join();
        if(_ThreadId)
            _isDetached = false;
    }
}

void myThread::detach()
{
    if(_isRunning && !_isDetached)
    {
        _ThreadId->detach();
        if(_ThreadId)
            _isDetached = true;
    }
}

std::thread* myThread::self()
{
    return _ThreadId;
}
