#include <iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T,N,M;
    int D[31][31];

    for(int i=0;i<=30;i++){
        D[i][1]=i;
        D[i][0]=1;
        D[i][i]=1;
    }
    for(int i=2;i<=30;i++){
        for(int j=1;j<i;j++){
            D[i][j]=D[i-1][j-1]+D[i-1][j];
        }
    }
    cin>>T;

    for(int i=0;i<T;i++){
        cin>>N>>M;
        cout<<D[M][N]<<'\n';
    }
    return 0;
}