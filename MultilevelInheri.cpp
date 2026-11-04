#include <iostream>
using namespace std;

class Student
{
protected:
    int roll_no;

public:
    void get_num(int r)
    {
        roll_no = r;
    }
    void put_num()
    {
        cout << "Roll No.:" << roll_no << endl;
    }
};
class Test : public Student
{
protected:
    float s1, s2;

public:
    void get_marks(float x, float y)
    {
        s1 = x;
        s2 = y;
    }
    void put_marks()
    {
        cout << "Subject 1: " << s1 << endl;
        cout << "Subject 2: " << s2 << endl;
    }
};
class Result : public Test
{
    float total;

public:
    void display()
    {
        total = s1 + s2;
        put_num();
        put_marks();
        cout << "Total Marks: " << total << endl;
    }
};
int main()
{
    Result r;
    int roll;
    float m1, m2;
    cout << "Enter Roll Number: ";
    cin >> roll;
    cout << "Enter Marks for Subject 1 and Subject 2: ";
    cin >> m1 >> m2;
    r.get_num(roll);
    r.get_marks(m1, m2);
    r.display();
    return 0;
}