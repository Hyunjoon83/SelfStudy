#include <iostream>
using namespace std;

int main(){
    int N=3000;
    int cnt=1;

    for(int i=0;i<N;i++){
        cout<<"Calculating count: "<<cnt++<<endl;
    }
    for(int i=0;i<N;i++){
        cout<<"Calculating count: "<<cnt++<<endl;
    }
    for(int i=0;i<N;i++){
        cout<<"Calculating count: "<<cnt++<<endl;
    }
    return 0;
}