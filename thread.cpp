#include "thread.h"
#include "choice.h"
#include "key/key.h"
#include "file/file.h"
#include "file/record.h"
#include "file/box.h"

using namespace std;

bool Thread::WaitChoice()
{
    Choice choice;
    choice.Get();
    if(choice.Success == true)
    {
        Ser = choice.Ser;
        return true;
    }
    return false;
}

bool Thread::WaitKey()
{
    Key key;
    if(key.GetKey == true)
    {
        NowKey = key.GottenKey;
        return true;
    }
    return false;
}

bool Thread::IsLegal()
{
    if(NowKey.size() == 6)
    {
        for(int i=0; i<6; ++i)
            if('0' > NowKey[i] || NowKey[i] > '9')
                return false;
        return true;
    }   
    return false;
}

Record Thread::Find()
{
    return nowfile.FileFind(NowKey);
}

void Thread::Open(int tar)
{

}

bool Thread::Close(int tar)
{

}

void Thread::sendmsg(int type,int boxnum)
{

}

void Thread::Run()
{
    while(WaitChoice() == false);
    
    while(WaitKey() == false);

    if(IsLegal() == false)
    {
        cout << "illegal key" << endl;
        return;
    }
    
    nowfile.Path = "E://c++//normal//wmbtestfile.txt";

    if(Ser == 0) //cun
    {
        Record ans = Find();
        if(ans.BoxNum != -1)
            return;

        TarBox tarbox(1);
        Record nowrec = tarbox.ToRec();
        nowfile.FileInsert(nowrec);
        sendmsg(0,tarbox);
        Open(tarbox.boxnum);

        bool overtime = false;
        // TODO: about overtime
        if(overtime)
            sendmsg(-1,BoxNum);
    }
    else  //Qu
    {
        Record ans = Find();
        if(ans.BoxNum == -1)
            return;
        
        nowfile.FileDelete(ans);
        Open(ans.BoxNum);

        bool overtime = false;
        // TODO: about overtime
        if(overtime);
    }
}
