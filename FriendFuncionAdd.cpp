#include <iostream>
using namespace std;

class ABC;

class XYZ
{
private:
    int data;

public:
    void setvalues(int x)
    {
        data = x;
    }
    friend void add(XYZ, ABC);
};

class ABC
{
private:
    int data;

public:
    void setvalues(int x)
    {
        data = x;
    }
    friend void add(XYZ, ABC);
};

void add(XYZ x, ABC a)
{
    cout << "The sum is " << x.data + a.data << endl;
}

int main()
{
    XYZ sum1;
    ABC sum2;
    int a, b;
    cout << "Enter value of first number:";
    cin >> a;
    cout << "Enter value of second number:";
    cin >> b;
    sum1.setvalues(a);
    sum2.setvalues(b);
    add(sum1, sum2);
    return 0;
}