#include <iostream>
#include <cstring>
using namespace std;

int main(void){
    char str1[]="Hanyang Univ ";
    char str2[]="Computer Software Engineering";
    char charS[100];

    cout<<strlen(str1)<<endl;
    cout<<strlen(str2)<<endl;
    strcpy(charS,str1);
    strcat(charS,str2);
    cout<<charS<<endl;
    if(strcmp(str1,str2)==0){
        cout<<"Two Strings are same."<<endl;
    }else{
        cout<<"Two Strings are different."<<endl;
    }
    return 0;
}