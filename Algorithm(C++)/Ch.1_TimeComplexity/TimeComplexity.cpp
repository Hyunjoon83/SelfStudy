#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
    int findNumber;
    srand(time(NULL));
    findNumber=rand()%100; //0~99까지의 랜덤 숫자
    
    for(int i=0;i<100;i++){
        if(i==findNumber){
            cout<<i;
            break;
        }
    }
    return 0;
}