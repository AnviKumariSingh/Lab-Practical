#include <iostream>
using namespace std;

class B
{
private:
    int a;

public:
    int b;

    void input()
    {
        cout << "Enter value of a:" << endl;
        cin >> a;
        cout << "Enter value of b:" << endl;
        cin >> b;
    }

    int get()
    {
        return a;
    }

    void display()
    {
        cout << "The value of a is " << a << endl;
    }
};
class D : public B
{
private:
    int d;

public:
    void mul()
    {
        cout << "Enter the value of d:" << endl;
        cin >> d;
        d = get() * b * d;
    }
    void show()
    {
        display();
        cout << "Product(a*b*d)=" << d << endl;
    }
};
int main()
{
    D sample;
    sample.input();
    sample.mul();
    sample.show();
    return 0;
}