#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

int main() {
    ll T,a,b;
    cin>>T;
    while(T--) {
        cin>>a>>b;
        if(a>b) {
            swap(a,b);
        }
        if(b>a*2) {
            cout<<"NO"<<endl;
        }else {
            if((a+b)%3==0) {
                cout<<"YES"<<endl;
            }else {
                cout<<"NO"<<endl;
            }
        }
    }
    return 0;
}




