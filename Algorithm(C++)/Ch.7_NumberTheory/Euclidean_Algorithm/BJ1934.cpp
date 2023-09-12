#include <iostream>
using namespace std;

int gcd(int a, int b){
    if(b==0){
        return a;
    }else{
        return gcd(b,a%b);
    }
}
//최소 공배수 = A*B/최대 공약수
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,A,B;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>A>>B;
        int result=A*B/gcd(A,B);
        cout<<result<<'\n';
    }
    return 0;
}