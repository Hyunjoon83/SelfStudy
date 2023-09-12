#include <iostream>
using namespace std;

class Base{
    public:
        Base(){
            cout<<"Base Constructor"<<endl;
        }
        void SimpleFunc(){
            cout<<"BaseOne"<<endl;
        }
};
class MiddleDerivedOne:virtual public Base{
    public:
        MiddleDerivedOne():Base(){
            cout<<"MiddleDerivedOne Constructor"<<endl;
        }
        void MiddleFuncOne(){
            SimpleFunc();
            cout<<"MiddleDerivedOne"<<endl;
        }
};
class MiddleDerivedTwo:virtual public Base{
    public:
        MiddleDerivedTwo():Base(){
            cout<<"MiddleDerivedTwo"<<endl;
        }
        void MiddleFuncTwo(){
            SimpleFunc();
            cout<<"MiddleDerivedTwo"<<endl;
        }
};

class LastDerived:public MiddleDerivedOne,public MiddleDerivedTwo{
    public:
        LastDerived():MiddleDerivedOne(),MiddleDerivedTwo(){
            cout<<"LstDerived Constructor"<<endl;
        }
        void ComplexFunc(){
            MiddleDerivedOne();
            MiddleDerivedTwo();
            SimpleFunc();
        }
};

int main(void){
    cout<<"Before making an object....."<<endl;
    LastDerived ldr;
    cout<<"After making an object....."<<endl;
    ldr.ComplexFunc();
    return 0;
}