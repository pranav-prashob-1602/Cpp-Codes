#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) begin(x), end(x)

#define sz(x) (int)(x).size()

#define ff first
#define ss second

#define mp make_pair

#define ll long long
#define ld long double

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n,t,x;
    cin>>n>>t;
    vector<ll> r,c;
    for(ll i=0;i<n;i++) {
        cin>>x;
        r.pb(x);
    }
    for(ll i=0;i<n;i++) {
        cin>>x;
        c.pb(x);
    }
    ll a[n][n];
    for(ll i=0;i<n;i++) {
         x = r[i];
         for(ll j=0;j<n;j++) {
            a[i][j] = c[j]+x;
         }
    }
    while(t--) {
        cin>>x1>>y1>>x2>>y2;

    }
    return 0;
}


