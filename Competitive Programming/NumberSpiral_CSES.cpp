
#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

int main() {
    ll x,y,T,res;
    cin>>T;
    while(T--) {
        cin>>x>>y;
        ll a = max(x,y);
        ll z = a*a - (a-1);
        if(a%2==0) {
            res =z + (x - y);
        } else {
            res = z - (x-y);
        }
        cout<<res<<endl;
    }
    return 0;
}


