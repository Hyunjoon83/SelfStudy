#include <iostream>
#include <vector>
using namespace std;

static vector<int> A;
static vector<int> tmp;

void mergeSort(int start, int end){
    if(end-start<1){
        return;
    }
    int mid=start+(end-start)/2;
    mergeSort(start,mid);
    mergeSort(mid+1,end);

    for(int i=start;i<=end;i++){
        tmp[i]=A[i];
    }
    int k=start;
    int index1=start;
    int index2=mid+1;

    while(index1<=mid && index2<=end){
        if(tmp[index1]>tmp[index2]){
            A[k]=tmp[index2];
            k++;
            index2++;
        }else{
            A[k]=tmp[index1];
            k++;
            index1++;
        }
    }
    while(index1<=mid){
        A[k]=tmp[index1];
        k++;
        index1++;
    }
    while(index2<=end){
        A[k]=tmp[index2];
        k++;
        index2++;
    }
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N;
    
    A=vector<int>(N+1,0);
    tmp=vector<int>(N+1,0);

    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    mergeSort(1,N);

    for(int i=1;i<=N;i++){
        cout<<A[i]<<endl;
    }
    return 0;
}