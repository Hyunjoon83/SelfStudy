#include <iostream>

namespace BestComImp1{
    void SimpleFunc(void){
        std::cout<<"Function that declared by BestCom"<<std::endl;
    }
}
namespace ProgComImp1{
    void SimpleFunc(void){
        std::cout<<"Function that declared by ProgCom"<<std::endl;
    }
}
int main(void){
    BestComImp1::SimpleFunc();
    ProgComImp1::SimpleFunc();
    return 0;
}