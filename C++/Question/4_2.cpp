#include <iostream>
#include <cstring>
using namespace std;

namespace COMP_POS{
    enum{
        CLERK,SENIOR,ASSIST,MANAGER
    };
    void ShowPositionInfo(int pos){
        switch(pos){
            case CLERK:
                cout<<"���"<<endl;
                break;
            case SENIOR:
                cout<<"����"<<endl;
                break;
            case ASSIST:
                cout<<"�븮"<<endl;
                break;
            case MANAGER:
                cout<<"����"<<endl;
        }
    }
}
class NameCard{
    private:
        char* name;
        char* company;
        char* phone;
        int position;
    public:
        NameCard(char* _name, char* _comp, char* _hp, int pos):position(pos){
            name=new char[strlen(_name)+1];
            company=new char[strlen(_comp)+1];
            phone=new char[strlen(_hp)+1];
            strcpy(name,_name);
            strcpy(company,_comp);
            strcpy(phone,_hp);
        }
        void ShowNameCardInfo(){
            cout<<"�̸�: "<<name<<endl;
            cout<<"ȸ��: "<<company<<endl;
            cout<<"��ȭ��ȣ: "<<phone<<endl;
            cout<<"����: ";COMP_POS::ShowPositionInfo(position);
            cout<<endl;
        }
        ~NameCard(){
            delete []name;
            delete []company;
            delete []phone;
        }
};
int main(void){
    NameCard manClerk("Lee","ABCEng","010-1111-2222",COMP_POS::CLERK);
    NameCard manSENIOR("Hong","OrangeEng","010-3333-4444",COMP_POS::SENIOR);
    NameCard manAssist("Kim","SoGoodComp","010-5555-6666",COMP_POS::ASSIST);
    manClerk.ShowNameCardInfo();
    manSENIOR.ShowNameCardInfo();
    manAssist.ShowNameCardInfo();
}