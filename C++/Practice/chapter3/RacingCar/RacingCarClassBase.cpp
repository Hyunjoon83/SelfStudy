#include <stdio.h>
#include <string.h>

namespace CAR_CONST {
    enum {
        ID_LEN = 20, MAX_SPD = 200, FUEL_STEP = 2, ACC_STEP = 1, BRK_STEP = 10
    };
}

class CAR {
private:
    char gamerID[CAR_CONST::ID_LEN];
    int fuelGauge;
    int curSpeed;
public:
    void InitMembers(char* ID, int fuel);
    void ShowCarState();
    void Accel();
    void Brake();
};

void CAR::InitMembers(char* ID, int fuel) {
    strcpy(gamerID, ID);
    fuelGauge = fuel;
    curSpeed = 0;
}

void CAR::ShowCarState() {
    printf("소유자ID: %s\n", gamerID);
    printf("연료량: %d%%\n", fuelGauge);
    printf("현재속도: %dkm/s\n", curSpeed);
}

void CAR::Accel() {
    if (fuelGauge <= 0)
        return;
    else
        fuelGauge -= CAR_CONST::FUEL_STEP;

    if ((curSpeed + CAR_CONST::ACC_STEP) >= CAR_CONST::MAX_SPD) {
        curSpeed = CAR_CONST::MAX_SPD;
        return;
    }
    curSpeed += CAR_CONST::ACC_STEP;
}

void CAR::Brake() {
    if (curSpeed < CAR_CONST::BRK_STEP) {
        curSpeed = 0;
        return;
    }
    curSpeed -= CAR_CONST::BRK_STEP;
}

int main(void) {
    CAR run99;
    run99.InitMembers("run99", 100);
    run99.Accel();
    run99.Accel();
    run99.Accel();
    run99.ShowCarState();
    run99.Brake();
    run99.ShowCarState();
    return 0;
}
