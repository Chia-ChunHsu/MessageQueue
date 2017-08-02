#ifndef QTCTHREAD_H
#define QTCTHREAD_H
#include <QThread>
#include <consumerthread.h>
#include <wqueue.h>
class QtCThread :public QThread
{
    Q_OBJECT
public:
    //explicit QtCThread(wqueue<WorkItem *> &queue,QWidget *parent = 0);
    explicit QtCThread(wqueue<WorkItem> &queue,QWidget *parent = 0);
protected:
    void run();
private:
    ConsumerThread* thread1;
    ConsumerThread* thread2;
    //wqueue<WorkItem*> _queue;
};

#endif // QTCTHREAD_H
