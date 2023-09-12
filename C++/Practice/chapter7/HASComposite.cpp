#include <iostream>
#include <cstring>
using namespace std;

class Gun{
    private:
        int bullet;
    public:
        Gun(int bnum):bullet(bnum){}
        void Shot(){
            cout<<"BBANG!"<<endl;
            bullet--;
        }
};
class Police{
    private:
        int handcuff;
        Gun* pistol; // Gun을 상속하는 것이 아닌 객체를 생성해서 참조
    public:
        Police(int bnum, int bcuff):handcuff(bcuff){
            if(bnum>0)
                pistol=new Gun(bnum);
            else
                pistol=NULL;
        }
        void PutHandCuff(){
            cout<<"SNAP!"<<endl;
            handcuff--;
        }
        void Shot(){
            if(pistol==NULL){
                cout<<"HUT BBANG!"<<endl;
            }else{
                pistol->Shot();
            }
        } // 상속이 아니라 참조이기 때문에 상속과 달리 Shot 함수를 새로 정의해야함
        ~Police(){
            if(pistol!=NULL){
                delete pistol;
            }
        }
};

int main(void){
    Police pman1(5,3);
    pman1.Shot();
    pman1.PutHandCuff();

    Police pman2(0,3);
    pman2.Shot();
    pman2.PutHandCuff();

    return 0;
}