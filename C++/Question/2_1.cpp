#include <iostream>
using namespace std;

void inc(int &num){
    num++;
}
void rev(int &num){
    num*=-1;
}
int main(void){
    int num;
    cin>>num;
    inc(num);
    cout<<num<<endl;
    rev(num);
    cout<<num<<endl;
    return 0;
}