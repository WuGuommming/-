#include "record.h"
using namespace std;

class TarBox
{
    int choice;
    int boxnum;

    TarBox(int choice)
    {
        TarBox::choice = choice;
        boxnum = 1;
    }

    Record ToRecord()
    {
        Record ans;
        ans.BoxNum = boxnum;
        
    }
}