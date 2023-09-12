#include <iostream>
#include <cstring>
using namespace std;

class MyFriendInfo{
    private:
        char* name;
        int age;
    public:
        MyFriendInfo(char* fname, int fage):age(fage){
            name=new char[strlen(fname)+1];
            strcpy(name,fname);
        }
        void ShowMyFriendInfo(){
            cout<<"Name: "<<name<<endl;
            cout<<"Age: "<<age<<endl;
        }
        ~MyFriendInfo(){
            delete []name;
        }
};
class MyFriendDetailInfo:public MyFriendInfo{
    private:
        char* addr;
        char* phone;
    public:
        MyFriendDetailInfo(char* fname, int fage, char* adr, char* pnum):MyFriendInfo(fname,fage){
            addr=new char[strlen(adr)+1];
            phone=new char[strlen(pnum)+1];
            strcpy(addr,adr);
            strcpy(phone,pnum);
        }
        void ShowMyFriendDetailInfo(){
            ShowMyFriendInfo();
            cout<<"Address: "<<addr<<endl;
            cout<<"Phone Number: "<<phone<<endl<<endl;
        }
        ~MyFriendDetailInfo(){
            delete []addr;
            delete []phone;
        }
};

int main(void){
    MyFriendDetailInfo friend1("Carrick",22,"London","010-1234-5678");
    MyFriendDetailInfo friend2("Bellingham",18,"Manchester","010-5678-1234");
    friend1.ShowMyFriendDetailInfo();
    friend2.ShowMyFriendDetailInfo();
    return 0;
}