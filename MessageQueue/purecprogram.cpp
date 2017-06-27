#include "purecprogram.h"


//void PureCProgram::Run()
//{
//    {

//    }
//}

void *PureCProgram::run()
{
    for(int i=0;i<100;i++)
    {
        Message* item = new Message(std::to_string(i).c_str());
        _queue.add(item);
    }
    return NULL;
}
