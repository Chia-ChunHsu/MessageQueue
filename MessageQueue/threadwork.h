#ifndef THREADWORK_H
#define THREADWORK_H

#include <QThread>
#include <purecprogram.h>
#include <myqueue.h>
#include <string>
#include <message.h>
#include <queue>
#include <QDebug>
class threadWork : public QThread
{
    Q_OBJECT
public:
    threadWork();
    int Size();
protected:
    void run();
signals:
    void sendProgress(int);
    void sendMessage(QString);
private:
    PureCProgram *pure = 0;
    MyQueue<Message*> queue;
};

#endif // THREADWORK_H
