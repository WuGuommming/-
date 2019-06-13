#include "string"
#include "record.h"
#include "vector"

using namespace std;

class File
{
    string Path;
    int tot;
    vector<Record> rec;

    void Init(string path)
    {
        rec.clear();
        Path = path;
        tot = 0;
    }

    void Load(string path);

    void WriteAll();

    Record FileFind(string tarkey);

    void FileInsert(Record tar);

    void FileDelete(Record tar);
}