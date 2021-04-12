#include<iostream>
#include<string.h>

using namespace std;

int main() {
    char str[100];
    cin>>str;
    char st1[100];
    strcpy(st1,str);
    strrev(str);
    if(strcmp(str,st1) == 0) {
        cout<<"Balanced";
    }else {
        cout<<"GAAND MARAAA";
    }
    return 0;
}
