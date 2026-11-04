#include <iostream>
using namespace std;

class marks
{
    int msem, esem;

public:
    marks()
    {
        msem = 0;
        esem = 0;
    }
    marks(int m, int e)
    {
        msem = m;
        esem = e;
    }
    void display();
    marks operator+(marks m1);
};

marks marks::operator+(marks m1)
{
    marks temp;
    temp.msem = msem + m1.msem;
    temp.esem = esem + m1.esem;
    return temp;
}

void marks::display()
{
    cout << "Marks in MSem: " << msem << endl;
    cout << "Marks in ESem:" << esem << endl;
}

int main()
{
    int a, b, c, d;
    cout << "Enter Mid sem and End sem marks of student X:";
    cin >> a >> b;
    cout << "Enter Mid sem and End sem marks of student Y:";
    cin >> c >> d;
    marks m1(a, b);
    marks m2(c, d);
    marks m3;
    m1.display();
    m2.display();
    m3 = m1 + m2;
    m3.display();
    return 0;
}