#include <string>

using namespace std;

class Record
{
public:
    string PhoneNum;
    bool EnPhone;
    string OrderNum;
    string Key;
    int BoxNum;

    bool equal(Record tar)
    {
        if(PhoneNum != tar.PhoneNum)
            return false;
        if(EnPhone != tar.EnPhone)
            return false;
        if(OrderNum != tar.OrderNum)
            return false;
        if(Key != tar.Key)
            return false;
        if(BoxNum != tar.BoxNum)
            return false;
        return true;
    }    

    void assign(Record tar)
    {
        PhoneNum = tar.PhoneNum;
        EnPhone = tar.EnPhone;
        OrderNum = tar.OrderNum;
        Key = tar.Key;
        BoxNum = tar.BoxNum;
    }
};