#include <iostream>
using namespace std;

int gcd(long a, long b){
    if(b==0){
        return a;
    }else{
        return gcd(b,a%b);
    }
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long A,B;
    cin>>A>>B;
    long result=gcd(A,B);

    while(result>0){
        cout<<1;
        result--;
    }
    cout<<'\n';
    return 0;
}