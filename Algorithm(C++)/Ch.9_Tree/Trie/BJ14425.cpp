#include <iostream>
#include <set>
using namespace std;

class Node{
    public:
        Node* next[26];
        bool isEnd;
        Node():isEnd(false){
            fill(next,next+26,nullptr);
        }
        ~Node(){
            for(auto& child:next)
                delete child;
        }
        void Insert(const char* key){
            if(*key==0){
                isEnd=true;
            }else{
                int next_index=*key-'a';
                if(next[next_index]==nullptr){
                    next[next_index]=new Node();
                }
                next[next_index]->Insert(key+1);
            }
        }
        Node* find(const char* key){
            if(*key==0){
                return this;
            }
            int next_index=*key-'a';

            if(next[next_index]==nullptr){
                return nullptr;
            }
            return next[next_index]->find(key+1);
        }
};

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,M;
    cin>>N>>M;
    Node* root=new Node();

    while(N>0){
        char text[501];
        cin>>text;
        root->Insert(text);
        N--;
    }
    int count=0;
    while(M>0){
        char text[501];
        cin>>text;
        Node* result=root->find(text);

        if(result && result->isEnd){
            count++;
        }
        M--;
    }
    cout<<count<<'\n';
}