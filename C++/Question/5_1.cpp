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
                cout<<"사원"<<endl;
                break;
            case SENIOR:
                cout<<"주임"<<endl;
                break;
            case ASSIST:
                cout<<"대리"<<endl;
                break;
            case MANAGER:
                cout<<"과장"<<endl;
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
        NameCard(const NameCard &copy):position(copy.position){
            name=new char[strlen(copy.name)+1];
            company=new char[strlen(copy.company)+1];
            phone=new char[strlen(copy.phone)+1];
            strcpy(name,copy.name);
            strcpy(company,copy.company);
            strcpy(phone,copy.phone);
        }
        void ShowNameCardInfo(){
            cout<<"이름: "<<name<<endl;
            cout<<"회사: "<<company<<endl;
            cout<<"전화번호: "<<phone<<endl;
            cout<<"직급: ";COMP_POS::ShowPositionInfo(position);
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
    NameCard copy1=manClerk;
    NameCard manSENIOR("Hong","OrangeEng","010-3333-4444",COMP_POS::SENIOR);
    NameCard copy2=manSENIOR;
    copy1.ShowNameCardInfo();
    copy2.ShowNameCardInfo();
    return 0;
}