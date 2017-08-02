#ifndef WORKITEM_H
#define WORKITEM_H
#include <stdlib.h>
#include <string>
#include <thread.h>
#include <wqueue.h>
class WorkItem
{
    std::string _message;
    int _number;
public:
    WorkItem(){
        _message = "default";
        _number = 0;
    }
    WorkItem(const char* message, size_t number)
        :_message(message), _number(number){}
    ~WorkItem(){}

    const char* getMessage(){return _message.c_str();}
    int getNumber(){return _number;}
};

#endif // WORKITEM_H
