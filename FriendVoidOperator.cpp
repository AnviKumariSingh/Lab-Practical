#include <iostream>
using namespace std;

class Space
{
    int x, y, z;

public:
    void getdata()
    {
        cout << "Enter the values of x,y,z: ";
        cin >> x >> y >> z;
    }
    void display()
    {
        cout << "The values of x,y,z are: " << x << "," << y << "," << z << endl;
    }
    friend void operator-(Space &s);
    friend void operator++(Space &s);
};

void operator++(Space &s)
{
    s.x++;
    s.y++;
    s.z++;
}

void operator-(Space &s)
{
    s.x = -s.x;
    s.y = -s.y;
    s.z = -s.z;
}
int main()
{
    Space s;
    s.getdata();
    s.display();
    ++s;
    cout << "After increment: ";
    s.display();
    -s;
    cout << "After negation: ";
    s.display();
    return 0;
}