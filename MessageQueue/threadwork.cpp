#include "threadwork.h"

threadWork::threadWork()
{
    if(!pure)
    {
        pure = new PureCProgram(queue);
    }
    pure->start();
    //qDebug()<<queue.size();
}

int threadWork::Size()
{
    return queue.size();
}

void threadWork::run()
{
    //std::queue a;
    //typedef Message* a;

    //Message temp;
    qDebug()<<queue.size();
//    while(1)
//    {
//        qDebug()<<queue.size();
//        //temp = queue.remove();
//        if(queue.size()>1)
//        {
//            Message* temp = queue.remove();
//            emit(QString(temp->getMessage()));
//        }
//    }
    //emit sendMessage(queue.);
}
