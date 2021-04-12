#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) begin(x), end(x)

#define sz(x) (int)(x).size()

#define f first
#define s second

#define mp make_pair

#define ll long long
#define ld long double

int main() {
    ll l,r;
    cin>>l>>r;
    ll cnt = 0;
    for(ll i=1;i<=r;i*=2) {
        for(ll j=1;(j*i)<=r;j*=3) {
            ll x = j*i;
            if(x>=l) {
                cnt++;
            }
        }
    }
    cout<<cnt;
    return 0;
}


