#include<iostream>
#include<string>

using namespace std;

int main() {
    long long int n,i,j,flag,m;
    cin>>n;
    string str[n],str1;
    for(i=0;i<n;i++) {
        cin>>str[i];
    }
    for(i=0;i<n;i++) {
        flag = 1;
        m=0;
        for(j=0;j<i;j++) {
            if(str[i] == str[j]){
                flag =0;
                m++;
                str1 = str[j];
            }
        }
        if(flag) {
            cout<<"OK\n";
        }else {
            cout<<str1<<m<<"\n";
        }
    }
    return 0;
}
