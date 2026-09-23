#include <iostream>
#include <string>
using namespace std;

class word
{
    string handsome;

public:
    word()
    {

        handsome = "Captain America";
    }
    void print()
    {
        cout << handsome << endl;
    }
};
int main()
{
    word wd;
    wd.print();
    return 0;
}