#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

int main() {
    ll T;
    ld a,b;
    cin>>T;
    while(T--) {
        cin>>a>>b;
        if(b<=a) {
            cout<<"YES"<<endl;
            continue;
        }
        ll x = a/2;
        ld y = (ld)b/(x+1);
        if(x+y<=a) {
            cout<<"YES"<<endl;
        } else {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}


