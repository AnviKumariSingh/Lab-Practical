#include <iostream>
using namespace std;

class Point
{
    int x, y;

public:
    Point(int a, int b)
    {
        x = a;
        y = b;
    }
    Point(const Point &p)
    {
        x = p.x;
        y = p.y;
    }
    void show()
    {
        cout << x << " " << y << endl;
    }
};
int main()
{
    int a, b;
    cout << "Enter x and y coordinates:";
    cin >> a >> b;
    Point p1(a, b);
    Point p2(p1);

    cout << "Coordinates of first point:";
    p1.show();
    cout << "Coordinates of copied point:";
    p2.show();
    return 0;
}