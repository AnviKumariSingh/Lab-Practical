#include <iostream>
using namespace std;

class Student{
    protected:
        int roll_no;
    public:
        void get_num(int r){
            roll_no=r;
        }
        void put_num(){
            cout<<"Roll No.:"<<roll_no<<endl;
        }
};
class Test:public Student {
    protected:
        float s1,s2;
}