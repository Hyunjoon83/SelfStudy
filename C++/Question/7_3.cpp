#include <iostream>
using namespace std;

class Rectangle{
    private:
        int width;
        int height;
    public:
        Rectangle(int row, int vertical):width(row),height(vertical){}
        void ShowAreaInfo(){
            cout<<"Area: "<<width*height<<endl;
        }

};
class Square:public Rectangle{
    public:
        Square(int side):Rectangle(side,side){}
};
int main(void){
    Rectangle rec(4,3);
    rec.ShowAreaInfo();

    Square sqr(7);
    sqr.ShowAreaInfo();
    return 0;
}