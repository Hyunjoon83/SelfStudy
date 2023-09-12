#include <iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int M,K,T;
    cin>>M;
    int D[51];
    double probability[51];
    double answer=0.0;

    for(int i=0;i<M;i++){
        cin>>D[i];
        T+=D[i];
    }
    cin>>K;
    for(int i=0;i<M;i++){
        if(D[i]>=K){
            probability[i]=1.0;
            for(int j=0;j<K;j++){
                probability[i]*=(double)(D[i]-j)/(T-j);
            }
        }
        answer+=probability[i];
    }
    cout<<fixed;
    cout.precision(9);
    cout<<answer<<endl;
    return 0;
}