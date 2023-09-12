#include <iostream>

namespace BestComImp1 {
    void SimpleFunc(void);
    void PrettyFunc(void);
}

namespace ProgComImpl {
    void SimpleFunc(void);
}

void BestComImp1::SimpleFunc(void) {
    std::cout << "Function that declared by BestCom" << std::endl;
    PrettyFunc();
    ProgComImpl::SimpleFunc();
}

void BestComImp1::PrettyFunc(void) {
    std::cout << "So pretty!!" << std::endl;
}

void ProgComImpl::SimpleFunc(void) {
    std::cout << "Function that declared by ProgCom" << std::endl;
}

int main(void) {
    BestComImp1::SimpleFunc();
    return 0;
}
