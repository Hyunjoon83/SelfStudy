#include <iostream>
#include <cstring>
using namespace std;

class Person{
    private:
        char* name;
        int age;
    public:
        Person(char* myname, int myage){
            int len=strlen(myname);
            name=new char[len];
            strcpy(name,myname);
            age=myage;
        }
        Person(const Person &copy):age(copy.age){
            name=new char[strlen(copy.name)+1];
            strcpy(name,copy.name);
        }
        void ShowPersonInfo(){
            cout<<"Name: "<<name<<endl;
            cout<<"Age: "<<age<<endl;
        }
        ~Person(){
            delete[] name;
            cout<<"Called destructor!"<<endl;
        }
};
int main(void){
    Person man1("Lee Dong Woo",29);
    Person man2=man1; //shallow copy -> default copy constructor 호출
    man1.ShowPersonInfo();
    man2.ShowPersonInfo();
    return 0;
}