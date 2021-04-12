#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

int main() {
    ll T,a,b,c;
    cin>>T;
    while(T--) {
        cin>>a>>b>>c;
        ll x = c - c%a + b;
        if(x<=c) {
            cout<<x<<endl;
            continue;
        }
        cout<<x-a<<endl;
    }
    return 0;
}


