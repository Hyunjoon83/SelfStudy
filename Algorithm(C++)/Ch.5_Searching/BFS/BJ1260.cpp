#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

static vector<vector<int>> A;
static vector<bool> visited;
static bool arrive;
void DFS(int node);
void BFS(int node);

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int V,E,start;
    cin>>V>>E>>start;

    arrive=false;
    A.resize(V+1);

    for(int i=0;i<E;i++){
        int s,e;
        cin>>s>>e;
        A[s].push_back(e);
        A[e].push_back(s);
    }

    for(int i=1;i<=V;i++){
        sort(A[i].begin(),A[i].end());
    }
    visited=vector<bool>(V+1,false);
    DFS(start);
    cout<<'\n';
    fill(visited.begin(),visited.end(),false);
    BFS(start);
    cout<<'\n';
}
void DFS(int node){
    cout<<node<<" ";
    visited[node]=true;

    for(int i:A[node]){
        if(!visited[i]){
            DFS(i);
        }
    }
}
void BFS(int node){
    queue<int> myQueue;
    myQueue.push(node);
    visited[node]=true;

    while(!myQueue.empty()){
        int now_node=myQueue.front();
        myQueue.pop();
        cout<<now_node<<" ";
        for(int i:A[now_node]){
            if(!visited[i]){
                visited[i]=true;
                myQueue.push(i);
            }
        }
    }
}