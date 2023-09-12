#include <iostream>
using namespace std;

#define ID_LEN 20
#define MAX_SPD 200
#define FUEL_STEP 2
#define ACC_STEP 10
#define BRK_STEP 10

struct Car{
    char gameID[ID_LEN]; //����� ID
    int fuelGauge; // ���ᷮ
    int curSpeed; // ����ӵ�
};
void showCarState(const Car &car){
    cout<<"������ ID: "<<car.gameID<<endl;
    cout<<"���ᷮ: "<<car.fuelGauge<<"%"<<endl;
    cout<<"����ӵ�: "<<car.curSpeed<<"km/h"<<endl;
}
void Accel(Car &car){
    if(car.fuelGauge<=0){
        return;
    }else{
        car.fuelGauge-=FUEL_STEP;
    }

    if(car.curSpeed+ACC_STEP>=MAX_SPD){
        car.curSpeed=MAX_SPD;
        return;
    }
    car.curSpeed+=ACC_STEP;
}
void Break(Car &car){
    if(car.curSpeed<BRK_STEP){
        car.curSpeed=0;
        return;
    }

    car.curSpeed-=BRK_STEP;
}

int main(void){
    Car run99={"run99",100,0};
    Accel(run99);
    Accel(run99);
    showCarState(run99);

    cout<<endl;

    Break(run99);
    showCarState(run99);

    cout<<endl;

    Car spd77={"spd77",100,0};
    Accel(spd77);
    Break(spd77);
    showCarState(spd77);
    return 0;
}