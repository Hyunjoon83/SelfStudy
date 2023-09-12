#include <iostream>

int main(void){
    int val1;
    std::cout<<"Input first number: ";
    std::cin>>val1;

    int val2;
    std::cout<<"Input second number: ";
    std::cin>>val2;

    int result=val1+val2;
    std::cout<<"Result: "<<result<<std::endl;
    return 0;
}