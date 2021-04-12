#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

int main() {
    ll T,N;
    cin>>T;
    while(T--) {
        cin>>N;
        if(N==1) {
            cout<<0<<endl;
        }else if(N==2) {
            cout<<1<<endl;
        }else if(N==3) {
            cout<<2<<endl;
        }else if(N%2) {
            cout<<3<<endl;
        }else {
            cout<<2<<endl;
        }
    }
    return 0;
}


