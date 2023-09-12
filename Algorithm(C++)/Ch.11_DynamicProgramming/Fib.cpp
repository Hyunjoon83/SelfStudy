#include <iostream>
#include <vector>
using namespace std;

static vector<int> A;

int Fib(int n){
    if(A[n]!=-1){
        return A[n];
    }
    return A[n]=Fib(n-1)+Fib(n-2);
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N;
    A.resize(N+1);

    for(int i=0;i<=N;i++){
        A[i]=-1;
    }
    A[0]=0;
    A[1]=1;
    Fib(N);
    cout<<A[N];
    return 0;
}