#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

int main() {
    ll T,n,cnt;
    cin>>T;
    while(T--) {
        cin>>n;
        ll cnt = 0;
        while(n>=0) {
            cnt++;
            ll x = (1LL << cnt) - 1;
            n-=(x*(x+1))/2;
        }
        cout<<cnt-1<<endl;
    }
    return 0;
}


