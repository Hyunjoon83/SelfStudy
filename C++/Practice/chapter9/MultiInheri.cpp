#include <iostream>
using namespace std;

class BaseOne{
    public:
        void SimpleFunc(){
            cout<<"BaseOne"<<endl;
        }
};
class BaseTwo{
    public:
        void SimpleFunc(){
            cout<<"BaseTwo"<<endl;
        }
};

class MultiDerived:public BaseOne,protected BaseTwo{
    public:
        void ComplexFunc(){
            BaseOne::SimpleFunc();
            BaseTwo::SimpleFunc();
        }
};

int main(void){
    MultiDerived mtd;
    mtd.ComplexFunc();
    return 0;
}