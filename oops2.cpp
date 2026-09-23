#include <iostream>
using namespace std;

class Circle
{
private:
    float radius;
    float pi = 3.14;

public:
    Circle(float r)
    {
        radius = r;
    }
    float getArea()
    {
        return pi * radius * radius;
    }
};
int main()
{
    float r;
    cout << "Enter the radius of circle:";
    cin >> r;
    Circle c(r);
    cout << "Area of the circle: " << c.getArea() << endl;
    return 0;
}