#include <iostream>

int main(void){
    int num;
    std::cin>>num;
    for(int i=1;i<num+1;i++){
        std::cout<<num<<"*"<<i<<"="<<num*i<<std::endl;
    }
    return 0;
}