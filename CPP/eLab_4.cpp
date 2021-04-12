
#include <iostream>
#include<string.h>
#include<sstream>

using namespace std;

int subString(string b) {
    int flag=0;
    for(int i=0;b[i]!='\0';i++) {
        if(b[i]=='2') {
            if(b[i+1] == '1') {
                flag=1;
                return flag;
            }
        }
    }
    return flag;
}

void NumCheck(string str) {
    stringstream geek(str);
  	int n=0;
  	int p;
  	geek>>n;
	if(n%21!=0) {
    	p=subString(str);
    	if(p) {
                cout<<"The streak is broken!\n";
                return;
    	}
    	cout<<"The streak lives still in our heart!\n";
    }else {
    	cout<<"The streak is broken!\n";
    }
}

int main() {
	int T;
  	string str;
  	cin>>T;
  	for(int i=0;i<T;i++) {
  		cin>>str;
      	NumCheck(str);
    }
	return 0;
}
