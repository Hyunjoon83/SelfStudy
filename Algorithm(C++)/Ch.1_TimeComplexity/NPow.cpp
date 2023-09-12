#include <iostream>
using namespace std;

int main(){
    int N=1000;
    int cnt=1;

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<"Calculating Count: "<<cnt++<<'\n';
        }
    }
    return 0;
}