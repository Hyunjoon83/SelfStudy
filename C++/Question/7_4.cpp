#include <iostream>
#include <cstring>
using namespace std;

class BOOK{
    private:
        char* title; // 책의 제목
        char* isbn; // 국제표준 도서번호
        int price; // 책의 가격
    public:
        BOOK(char* title, char* isbn, int value):price(value){
            this->title=new char[strlen(title)+1];
            this->isbn=new char[strlen(isbn)+1];
            strcpy(this->title,title);
            strcpy(this->isbn,isbn);
        }
        void ShowBookInfo(){
            cout<<"Name: "<<title<<endl;
            cout<<"ISBN: "<<isbn<<endl;
            cout<<"Price: "<<price<<endl;
        }
        ~BOOK(){
            delete []title;
            delete []isbn;
        }
};
class EBOOK:public BOOK{
    private:
        char* DRMkey; //보안 관련 키
    public:
        EBOOK(char* title, char* isbn, int value, char* key):BOOK(title,isbn,value){
            DRMkey=new char[strlen(key)+1];
            strcpy(DRMkey,key);
        }
        void ShowBookInfo(){
            ShowBookInfo();
            cout<<"Master Key: "<<DRMkey<<endl;
        }
        ~EBOOK(){
            delete []DRMkey;
        }
};
int main(void){
    BOOK book("Good C++","555-12345-890-0",20000);
    book.ShowBookInfo();
    cout<<endl;
    EBOOK ebook("Good C++","555-12345-890-1",10000,"fdx9w0i8kiw");
    ebook.ShowBookInfo();
    return 0;
}