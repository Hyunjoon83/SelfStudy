#include <iostream>
using namespace std;

int main(void){
    int num=12;
    int *ptr=&num;
    int **dptr=&ptr;

    int &ref=num; //num의 별칭 = ref -> num의 값을 ref에 할당
    int *(&pref)=ptr; //ptr의 별칭 = pref -> ptr가 가리키는 값을 pref에 할당
    int **(&dpref)=dptr; //dptr의 별칭 = dpref -> dptr가 가리키는 ptr가 가리키는 num 값을 dpref에 할당

    cout<<ref<<endl;
    cout<<*pref<<endl;
    cout<<**dpref<<endl;
    return 0;
}