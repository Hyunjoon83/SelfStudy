#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,M;
    cin>>N;
    vector<int> A(N);

    
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    sort(A.begin(),A.end());
    cin>>M;

    for(int i=0;i<M;i++){
        bool find=false;
        int target;
        cin>>target;

        int start=0;
        int end=A.size()-1;

        while(start<=end){
            int midI=(start+end)/2;
            int midV=A[midI];

            if(midV>target){
                end=midI-1;
            }else if(midV<target){
                start=midI+1;
            }else{ //midV==target
                find=true;
                break;
            }
        }
        if(find){
            cout<<1<<'\n';
        }else{
            cout<<0<<'\n';
        }
    }
    return 0;
}