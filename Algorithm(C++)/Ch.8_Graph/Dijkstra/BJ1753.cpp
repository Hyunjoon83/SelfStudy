#include <iostream>
#include <queue>
#include <vector>
#include <limits.h>
using namespace std;

typedef pair<int, int> edge;
static int V,E,K;
static vector<vector<edge>> mList;
static vector<int> mDistance;
static vector<bool> visited;
static priority_queue<edge,vector<edge>,greater<edge>> q;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>V>>E>>K;
    mDistance.resize(V+1);
    std::fill(mDistance.begin(),mDistance.end(),INT_MAX);
    visited.resize(V+1);
    std::fill(visited.begin(),visited.end(),INT_MAX);
    mList.resize(V+1);

    for(int i=0;i<E;i++){
        int u,v,w;
        cin>>u>>v>>w;
        mList[u].push_back(make_pair(v,w));
    }
    q.push(make_pair(0,K));
    mDistance[K]=0;

    while(!q.empty()){
        edge current=q.top();
        q.pop();
        int c_v=current.second;
        if(visited[c_v])
            continue;
        visited[c_v]=true;

        for(int i=0;i<mList[c_v].size();i++){
            edge tmp=mList[c_v][i];
            int next=tmp.first;
            int value=tmp.second;

            if(mDistance[next]>mDistance[c_v]+value){
                mDistance[next]=value+mDistance[c_v];
                q.push(make_pair(mDistance[next],next));
            }
        }
    }
    for(int i=1;i<=V;i++){
        if(visited[i])
            cout<<mDistance[i]<<'\n';
        else
            cout<<"INF"<<'\n';
    }
    return 0;
}