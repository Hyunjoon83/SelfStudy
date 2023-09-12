#include <iostream>
using namespace std;

class Point{
    private:
        int xpos, ypos;
    public:
        Point(int x=0, int y=0):xpos(x),ypos(y){}
        void ShowData() const{
            cout<<'['<<xpos<<", "<<ypos<<']'<<endl;
        }
};

template <typename T>
void SwapData(T& num1, T& num2){
    T temp=num1;
    num1=num2;
    num2=temp;
}

int main(void){
    Point pos1(3,4);
    Point pos2(10,20);
    SwapData(pos1, pos2);
    pos1.ShowData();
    pos2.ShowData();
    return 0;
}