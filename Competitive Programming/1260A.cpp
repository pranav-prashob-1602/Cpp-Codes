#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

int main() {
    ll T,N,c,s;
    cin>>T;
    while(T--) {
        cin>>c>>s;
        if(c>=s) {
            cout<<s<<endl;
        }else {
            ll x = s/c;
            ll y = x*x*(c- s%c)+(x+1)*(x+1)*(s%c);;
            cout<<y<<endl;
        }
    }
    return 0;
}
