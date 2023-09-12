#include <iostream>
using namespace std;

class Person{
    public:
        void Sleep(){
            cout<<"Sleep"<<endl;
        }
};
class Student:public Person{
    public:
        void Study(){
            cout<<"Study"<<endl;
        }
}; // Person class를 상속하는 Student class
class PartTimeStudent:public Student{
    public:
        void Work(){
            cout<<"Work"<<endl;
        }
};
int main(void){
    Person* ptr1=new Student(); //Student 객체를 가리키는 Person형 포인터 ptr1
    Person* ptr2=new PartTimeStudent(); //PartTimeStudent 객체를 가리키는 Person형 포인터 ptr2
    Student* ptr3=new PartTimeStudent(); //PartTimeStudent 객체를 가리키는 Student형 포인터 ptr3

    ptr1->Sleep();
    ptr2->Sleep();
    ptr3->Study();

    delete ptr1,ptr2,ptr3;
    return 0;
}