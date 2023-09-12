#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main(void){
    srand(time(NULL));
    int a,b,c,d,e;
    for(int i=0;i<5;i++){
        printf("Random Number #%d: %d\n",i+1,rand()%100);
    }
    return 0;
}