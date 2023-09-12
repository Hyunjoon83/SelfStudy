#include <iostream>

void myFunc(void){
    std::cout<<"MyFunc(void) called"<<std::endl;
}
void myFunc(char c){
    std::cout<<"MyFunc(char c) called"<<std::endl;
}
void myFunc(int a, int b){
    std::cout<<"MyFunc(int a, int b) called"<<std::endl;
}
int main(void){
    myFunc();
    myFunc('A');
    myFunc(12,13);
    return 0;
}