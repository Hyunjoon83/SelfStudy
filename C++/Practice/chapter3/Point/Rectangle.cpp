#include <iostream>
#include "Rectangle.h"
using namespace std;

Rectangle::Rectangle(const int &x1, const int &y1, const int &x2, const int &y2):upLeft(x1,y1),lowRight(x2,y2){
    
}
void Rectangle::ShowRecInfo() const{
    cout<<"Up Left: "<<'['<<upLeft.GetX()<<", "<<upLeft.GetY()<<']'<<endl;
    cout<<"Low Right: "<<'['<<lowRight.GetX()<<", "<<lowRight.GetY()<<']'<<endl;
}
