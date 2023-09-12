#include <iostream>
#include <cstring>
using namespace std;

class Computer{
    private:
        char owner[50];
    public:
        Computer(char* name){
            strcpy(owner,name);
        }
        void Calculate(){
            cout<<"Calculate what you ordered."<<endl;
        }
};
class NoteBookCom : public Computer{
    private:
        int Battery;
    public:
        NoteBookCom(char* name, int initChag):Computer(name),Battery(initChag){}
        void Charging(){
            Battery+=5;
        }
        void UseBattery(){
            Battery-=1;
        }
        void MovingCal(){
            if(GetBatteryInfo()<1){
                cout<<"Need recharging battery"<<endl;
                return;
            }
            cout<<"While moving..."<<endl;
            Calculate();
            UseBattery();
        }
        int GetBatteryInfo(){
            return Battery;
        }
};
class TabletNoteBook : public NoteBookCom{
    private:
        char regstPenModel[50];
    public:
        TabletNoteBook(char* name, int initChag, char* pen):NoteBookCom(name,initChag){
            strcpy(regstPenModel,pen);
        }
        void Write(char* penInfo){
            if(GetBatteryInfo()<1){
                cout<<"Need recharging battery"<<endl;
                return;     
            }
            if(strcmp(regstPenModel,penInfo)!=0){
                cout<<"This is not a registered pen"<<endl;
                return;
            }
            cout<<"Processing written objects"<<endl;
            UseBattery();
        }
};
int main(void){
    NoteBookCom nc("Richard",5);
    TabletNoteBook tn("Patrick",5,"ISE-241-242");
    nc.MovingCal();
    tn.Write("ISE-241-242");
    return 0;
}