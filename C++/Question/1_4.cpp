#include <iostream>

int main(){
    int num;
    while(1){
        std::cout<<"Enter sales amount in units of 10,000 dollar(-1 to end): ";
        std::cin>>num;
        if(num==-1){
            break;
        }
        std::cout<<"This month's salary: $"<<50+num*0.12<<std::endl;
    }
    return 0;
}