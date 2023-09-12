#include <iostream>
using namespace std;

class CountryArea{
    public:
        const static int RUSSIA =1707540;
        const static int CANADA =998467;
        const static int CHINA = 957290;
        const static int SOUTH_KOREA = 9922;
};
int main(void){
    cout<<"Russia: "<<CountryArea::RUSSIA<<" km^2"<<endl;
    cout<<"Canada: "<<CountryArea::CANADA<<" km^2"<<endl;
    cout<<"China: "<<CountryArea::CHINA<<" km^2"<<endl;
    cout<<"South Korea: "<<CountryArea::SOUTH_KOREA<<" km^2"<<endl;
    return 0;
}