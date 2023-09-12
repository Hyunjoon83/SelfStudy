#include <iostream>

int main(void){
    char name[100];
    char lang[200];

    std::cout<<"What is your name? ";
    std::cin>>name;

    std::cout<<"What is your favorite programming language? ";
    std::cin>>lang;

    std::cout<<"My name is "<<name<<"."<<std::endl;
    std::cout<<"My favorite language is "<<lang<<".\n";
    return 0;
}