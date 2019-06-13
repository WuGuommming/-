#include "thread.h"
#include "inc/choice.h"
#include "inc/key/key.h"
#include "file/file.h"
#include "file/record.h"
#include "file/box.h"


using namespace std;

bool Thread::WaitChoice(QDialog view,int type) // type 1 for cun&qu; type 2 for leng&re
{
    Choice choice;
    choice.Get(view);
    if(choice.Success == true)
    {
        if(type == 1)
            Ser = choice.Ser;
        else
            isHot = choice.Ser;
        return true;
    }
    return false;
}

bool Thread::WaitKey(QDialog keydialog)
{
    for(int i=0; i<1e6; ++i)
    {
        //TODO: get view input
        if(keydialog.*** == true)
        {
            NowKey = ***
            return true;
        }
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
    QWidget view();
    // TODO: new a view object
    QDialog choice1();
    while(WaitChoice(choice1,1) == false);
    if(Ser == 1)
    {
        QDialog choice2();
        while(WaitChoice(choice2,2) == false);
    }

    QDiolog keydialog();
    while(WaitKey(keydialog) == false);

    /*
    if(IsLegal() == false)
    {
        cout << "illegal key" << endl;
        return;
    }
    */
    
    nowfile.Path = "E://wmbtestfile.txt";

    if(Ser == 1) //cun
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
    else  //qu
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
