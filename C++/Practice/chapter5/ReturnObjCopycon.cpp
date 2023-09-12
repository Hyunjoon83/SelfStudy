#include <iostream>
using namespace std;

class SoSimple{
    private:
        int num;
    public:
        SoSimple(int n):num(n){

        }
        SoSimple(const SoSimple &copy):num(copy.num){
            cout<<"Called SoSimple(const SoSimple &copy)"<<endl;
        }
        SoSimple& AddNum(int n){
            num+=n;
            return *this; //객체 자신을 참조값으로 반환
        }
        void ShowData(){
            cout<<"num: "<<num<<endl;
        }
};
SoSimple SimpleFuncObj(SoSimple ob){
    cout<<"Before return"<<endl;
    return ob;
} //parameter를 copy constructor로 전달
int main(void){
    SoSimple obj(7);
    SimpleFuncObj(obj).AddNum(30).ShowData(); //SFO 함수가 반환한 객체를 대상으로 AddNum 함수 호출 -> 반환한 참조값을 대상으로 ShowData함수 호출
    obj.ShowData(); //obj를 대상으로 ShowData 함수 호출(위에꺼와 비교하기 위해)
    return 0;
}