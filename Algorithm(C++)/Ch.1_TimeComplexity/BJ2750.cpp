#include <iostream>
#include <algorithm>
using namespace std;

void swap(int* a, int* b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
int main(void){
    int N;
    cin>>N;

    int* num=new int[N];

    for(int i=0;i<N;i++){
        cin>>num[i];
    }
    bool swapped;
    for (int i=0;i<N-1;i++){
        swapped = false;
        for (int j=0; j<N-i-1;j++){
            if(num[j]>num[j+1]){
                swap(num+j,num+j+1);
                swapped=true;
            }
        }
        if(!swapped){
            break;
        }
    }
    for(int i=0;i<N;i++){
        cout<<num[i]<<endl;
    }
    delete []num;
    return 0;
}