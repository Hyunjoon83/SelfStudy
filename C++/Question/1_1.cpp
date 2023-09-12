#include <iostream>

int main(void){
    int num;
    int sum=0;
    for(int i=0;i<5;i++){
        std::cout<<i+1<<"'s input number: ";
        std::cin>>num;
        sum+=num;
    }
    std::cout<<"Sum: "<<sum;
    return 0;
}