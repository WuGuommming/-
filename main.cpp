#include "iostream"
#include "thread.h"
using namespace std;

int main()
{
    int a;
    while(true) // TODO: pend awake
    {
        Thread mainthread;
        mainthread.Run();
    }
}