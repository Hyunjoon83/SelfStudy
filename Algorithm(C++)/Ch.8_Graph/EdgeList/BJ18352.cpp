#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

void BFS(int node);
static vector<int> visited;
static vector<int> answer;
static vector<vector<int>> A;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long N,M,K,X;
    cin>>N>>M>>K>>X;
    A.resize(N+1);

    for(int i=0;i<M;i++){
        int S,E;
        cin>>S>>E;
        A[S].push_back(E);
    }
    visited.resize(N+1);
    for(int i=0;i<=N;i++){
        visited[i]=-1;
    }

    BFS(X);

    for(int i=0;i<=N;i++){
        if(visited[i]==K){
            answer.push_back(i);
        }
    }
    if(answer.empty()){
        cout<<"-1"<<'\n';
    }else{
        sort(A.begin(),A.end());
        for(int temp:answer){
            cout<<temp<<'\n';
        }
    }
    return 0;
}
void BFS(int node){
    queue<int> Q;
    Q.push(node);
    visited[node]++;

    while(!Q.empty()){
        int now_node=Q.front();
        Q.pop();
        for(int i:A[now_node]){
            if(visited[i]==-1){
                visited[i]=visited[now_node]+1;
                Q.push(i);
            }
        }
    }
}