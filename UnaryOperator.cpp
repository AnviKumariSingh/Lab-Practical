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
    void operator-()
    {
        x = -x;
        y = -y;
        z = -z;
    }
};
int main()
{
    Space s;
    s.getdata();
    s.display();
    -s;
    cout << "After negation: ";
    s.display();
    return 0;
}