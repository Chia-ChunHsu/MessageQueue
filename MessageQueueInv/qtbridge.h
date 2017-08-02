#ifndef QTBRIDGE_H
#define QTBRIDGE_H

#include <QThread>
#include <wqueue.h>
//#include <consumerthread.h>
#include <updatemanager.h>
#include <workitem.h>
class QtBridge:public QThread
{
    Q_OBJECT
public:
    QtBridge();
    void updateProgress(WorkItem progress);
    void updateProgress2(WorkItem progress);
protected:
    void run();
private:
    wqueue<WorkItem> messages;
    wqueue<WorkItem> messages2;
    UpdateManager<QtBridge>* manager;
    UpdateManager<QtBridge>* manager2;

signals:
    void sendProgress(int);
    void sendMessage(QString);

    void sendProgress2(int);
    void sendMessage2(QString);

};

#endif // QTBRIDGE_H
