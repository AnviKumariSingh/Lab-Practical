#include <iostream>
using namespace std;

class Sample
{
private:
    int a, b;

public:
    void setvalues(int x, int y)
    {
        a = x;
        b = y;
    }
    friend float mean(Sample s);
};

float mean(Sample s)
{
    return (s.a + s.b) / 2.0;
}

int main()
{
    Sample sum;
    int x, y;
    cout << "Enter the values of a and b:";
    cin >> x >> y;
    sum.setvalues(x, y);
    cout << "The mean value is " << mean(sum) << endl;
    return 0;
}
