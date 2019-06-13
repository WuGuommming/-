#include <string>
using namespace std;

class Choice
{
public:
    bool Success;
    int Ser;

    void Get(QDialog dialog)
    {
        for(int i=0; i<1e6; ++i)
        {
            //TODO: get view input
            if(dialog.*** == true)
            {
                Success = true;
                Ser = ***
                return;
            }
        }
        Success = false;
    }
}