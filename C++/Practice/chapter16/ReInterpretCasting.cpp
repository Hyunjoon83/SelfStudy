#include <iostream>
using namespace std;

int main(void){
    int num=0x10203;
    char* ptr=reinterpret_cast<char*>(&num);

    for(int i=0;i<sizeof(num);i++){
        cout<<static_cast<int>(*(ptr+i))<<endl;
    }
    return 0;
}