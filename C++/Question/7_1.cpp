#include <iostream>
using namespace std;

class Car{
    private:
        int gasolineGauge;
    public:
        Car(int gas):gasolineGauge(gas){}
        int GetGasGauge(){
            return gasolineGauge;
        }
};
class HybridCar:public Car{
    private:
        int electricGauge;
    public:
        HybridCar(int gas, int elec):Car(gas),electricGauge(elec){}
        int GetElecGauge(){
            return electricGauge;
        }
};
class HybridWaterCar:public HybridCar{
    private:
        int waterGauge;
    public:
        HybridWaterCar(int gas, int elec, int water):HybridCar(gas,elec),waterGauge(water){}
        void ShowCurrentGauge(){
            cout<<"Rest Gasoline: "<<GetGasGauge()<<endl;
            cout<<"Rest Electricity: "<<GetElecGauge()<<endl;
            cout<<"Rest Water: "<<waterGauge<<endl;
        }
};

int main(void){
    HybridWaterCar hbwc(79,65,35);
    hbwc.ShowCurrentGauge();
    return 0;
}