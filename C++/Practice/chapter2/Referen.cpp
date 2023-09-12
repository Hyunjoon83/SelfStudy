#include <iostream>
using namespace std;

int main(void){
    int num1=1020;
    int &num2=num1; //num1, num2가 동일한 메모리공간 참조

    num2=3047;
    cout<<"VAL: "<<num1<<endl;
    cout<<"REF: "<<num2<<endl;

    cout<<"VAL: "<<&num1<<endl;
    cout<<"REF: "<<&num2<<endl;
    // num1, num2의 주소값 출력
    return 0;
}