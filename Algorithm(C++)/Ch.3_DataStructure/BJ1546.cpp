#include <iostream>
using namespace std;

int main(void){
    int M=0;
    cin>>M;
    int A[1000];

    long Max=0;
    long Sum=0;
    double NewScore=0;

    for(int i=0;i<M;i++){
        cin>>A[i];
    }
    for(int i=0;i<M;i++){
        if(A[i]>Max)
            Max=A[i];
        Sum+=A[i];
    }
    NewScore=Sum*100.0/Max/M;
    cout<<NewScore<<'\n';

    return 0;
}