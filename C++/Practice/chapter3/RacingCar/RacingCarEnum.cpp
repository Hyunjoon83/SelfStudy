#include <iostream>
using namespace std;

namespace CAR_CONST{
    enum{
        ID_LEN=20,
        MAX_SPEED=200,
        FUEL_STEP=2,
        ACC_STEP=10,
        BRK_STEP=10
    };
}
struct Car{
    char gameID[CAR_CONST::ID_LEN]; //����� ID
    int fuelGauge; // ���ᷮ
    int curSpeed; // ����ӵ�

    void showCarState(){
        cout<<"������ ID: "<<gameID<<endl;
        cout<<"���ᷮ: "<<fuelGauge<<"%"<<endl;
        cout<<"����ӵ�: "<<curSpeed<<"km/h"<<endl;
    }
    void Accel(){
        if(fuelGauge<=0){
            return;
        }else{
            fuelGauge-=CAR_CONST::FUEL_STEP;
        }

        if(curSpeed+CAR_CONST::ACC_STEP>=CAR_CONST::MAX_SPEED){
            curSpeed=CAR_CONST::MAX_SPEED;
            return;
        }
        curSpeed+=CAR_CONST::ACC_STEP;
    }
    void Break(){
        if(curSpeed<CAR_CONST::BRK_STEP){
            curSpeed=0;
            return;
        }

        curSpeed-=CAR_CONST::BRK_STEP;
    }
};

int main(void){
    Car run99={"run99",100,0};
    run99.Accel();
    run99.Accel();
    run99.showCarState();

    cout<<endl;

    run99.Break();
    run99.showCarState();

    cout<<endl;

    Car spd77={"spd77",100,0};
    spd77.Accel();
    spd77.Break();
    spd77.showCarState();
    return 0;
}