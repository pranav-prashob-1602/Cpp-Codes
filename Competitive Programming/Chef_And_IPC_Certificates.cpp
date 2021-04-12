#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

int main() {
    ll T,m,k,x,q;
    cin>>T>>m>>k;
    ll cnt = 0;
    while(T--) {
        ll sum = 0;
        for(ll i=0;i<k;i++) {
            cin>>x;
            sum+=x;
        }
        cin>>q;
        if(sum>=m && q<=10) {
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}


