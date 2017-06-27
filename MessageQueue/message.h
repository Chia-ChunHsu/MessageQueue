#ifndef MESSAGE_H
#define MESSAGE_H
#include <string>

class Message
{
public:
    Message(){}
    Message(const char* message):_mes(message){}
    const char* getMessage(){return _mes.c_str();}
private:
     std::string _mes;
};

#endif // MESSAGE_H
