#include <iostream>
using namespace std;

class SinivelCap{
    public:
        void Take() const{
            cout<<"Äà¹°ÀÌ ½Ï~ ³³´Ï´Ù."<<endl;
        }
};//Äà¹° Ã³Ä¡¿ë Ä¸½¶
class SneezeCap{
    public:
        void Take() const{
            cout<<"ÀçÃ¤±â°¡ ¸Ü½À´Ï´Ù."<<endl;
        }
};//ÀçÃ¤±â Ã³Ä¡¿ë Ä¸½¶
class SnuffleCap{
    public:
        void Take() const{
            cout<<"ÄÚ°¡ »½ ¶Õ¸³´Ï´Ù."<<endl;
        }
};//ÄÚ¸·Èû Ã³Ä¡¿ë Ä¸½¶
class ColdPatient{
    public:
        void TakeSinivelCap(const SinivelCap &cap) const{
            cap.Take();
        }
        void TakeSneezeCap(const SneezeCap &cap) const{
            cap.Take();
        }
        void TakeSnuffleCap(const SnuffleCap &cap) const{
            cap.Take();
        }
};
int main(void){
    SinivelCap scap;
    SneezeCap zcap;
    SnuffleCap ncap;

    ColdPatient sufferer;
    sufferer.TakeSinivelCap(scap);
    sufferer.TakeSneezeCap(zcap);
    sufferer.TakeSnuffleCap(ncap);
    return 0;
}