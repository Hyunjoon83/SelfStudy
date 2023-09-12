#include <iostream>
#include <cstring>
using namespace std;

class String{
    private:
        int len;
        char* str;
    public:
        String();
        String(const char* s);
        String(const String& s);
        ~String();
        String& operator=(const String& s);
        String& operator+=(const String& s);
        bool operator==(const String& s);
        String operator+ (const String& s);

        friend ostream& operator<<(ostream& os, const String& s);
        friend istream& operator>>(istream& is, const String& s);
};

String::String(){
    len=0;
    str=NULL;
}
String::String(const char* s){
    len=strlen(s)+1;
    str=new char[len];
    strcpy(str,s);
}
String::String(const String& s){
    len=s.len;
    str=new char[len];
    strcpy(str,s.str);
}
String::~String(){
    if(str!=NULL){
        delete []str;
    }
}

String& String::operator=(const String& s){
    if(str!=NULL)
        delete []str;
    len=s.len;
    str=new char[len];
    strcpy(str,s.str);
    return *this;
}
String& String::operator+=(const String& s){
    len+=(s.len-1);
    char* tempStr=new char[len];
    strcpy(tempStr,str);
    strcat(tempStr,s.str);

    if(str!=NULL)
        delete []str;
    str=tempStr;
    return *this;
}
/* 
String& String::operator+= (const String& s){
		*this=*this+s;
		return *this;
}
*/
bool String::operator==(const String& s){
    return strcmp(str,s.str)?false:true;
}
String String::operator+(const String& s){
    char* tempStr=new char[len];
    strcpy(str,str);
    strcat(tempStr,s.str);

    String temp(tempStr);
    delete []tempStr;
    return temp;
}

ostream& operator<<(ostream& os, const String& s){
    os<<s.str;
    return os;
}
istream& operator>>(istream& is, String& s){
    char str[100];
    is>>str;
    s=String(str);
    return is;
}

int main(void){
    string str1="I like ";
    string str2="string class.";
    string str3=str1+str2;

    cout<<str1<<endl;
    cout<<str2<<endl;
    cout<<str3<<endl;

    str1+=str2;
    if(str1==str3){
        cout<<"Same string!"<<endl;
    }else{
        cout<<"Different string!"<<endl;
    }

    string str4;
    cout<<"Input string: ";
    cin>>str4;
    cout<<"string: "<<str4<<endl;
    return 0;
}