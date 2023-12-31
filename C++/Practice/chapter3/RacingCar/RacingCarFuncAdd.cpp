#include <iostream>
using namespace std;

#define ID_LEN 20
#define MAX_SPD 200
#define FUEL_STEP 2
#define ACC_STEP 10
#define BRK_STEP 10

struct Car{
    char gameID[ID_LEN]; //사용자 ID
    int fuelGauge; // 연료량
    int curSpeed; // 현재속도

    void showCarState(){
        cout<<"소유자 ID: "<<gameID<<endl;
        cout<<"연료량: "<<fuelGauge<<"%"<<endl;
        cout<<"현재속도: "<<curSpeed<<"km/h"<<endl;
    }
    void Accel(){
        if(fuelGauge<=0){
            return;
        }else{
            fuelGauge-=FUEL_STEP;
        }

        if(curSpeed+ACC_STEP>=MAX_SPD){
            curSpeed=MAX_SPD;
            return;
        }
        curSpeed+=ACC_STEP;
    }
    void Break(){
        if(curSpeed<BRK_STEP){
            curSpeed=0;
            return;
        }

        curSpeed-=BRK_STEP;
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