#include "vector"
#include "file.h"
#include "iostream"
#include "cstdio"

using namespace std;

Record File::FileFind(string tarkey)
{
    int len = rec.size();
    for(int i=0; i<len; ++i)
    {
        if(rec[i].Key == tarkey)
            return rec[i];
    }
    return {"", 0, "", "", -1};
}

void File::WriteAll()
{
    freopen(Path.data,"w",stdout);

    int len = rec.size();
    for(int i=0; i<len; ++i)
        cout << rec[i].PhoneNum
            << " " << rec[i].EnPhone
            << " " << rec[i].OrderNum
            << " " << rec[i].Key
            << " " << rec[i].BoxNum;

    fclose(stdout);
}

void File::FileInsert(Record tar)
{
    tot++;
    rec.push_back(tar);

    File::WriteAll();
}

void File::FileDelete(Record tar)
{
    int len = rec.size();
    for(int i=0; i<len; ++i)
    {
        if(rec[i].equal(tar))
        {
            rec[i].assign(rec[len-1]);
            rec.pop_back();
            break;
        }
    }

    File::WriteAll();
}
