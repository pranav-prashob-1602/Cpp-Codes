#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

int main() {
    ll T,a,b;
    cin>>T;
    while(T--) {
        cin>>a>>b;
        b++;
        ll cnt = 0;
        while(b!=0) {
            cnt++;
            b=b/10;
        }
        cout<<a*(cnt-1)<<endl;
    }
    return 0;
}


