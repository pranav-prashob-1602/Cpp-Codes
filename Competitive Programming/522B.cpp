#include<bits/stdc++.h>

/*

shinchanCoder Here!!

*/

using namespace std;

#define pb push_back
#define all(x) begin(x), end(x)

#define sz(x) (int)(x).size()

#define ff first
#define ss second

#define mp make_pair

#define ll long long
#define ld long double

#define mod 1000000007

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll T,x,y,w=0,n;
    cin>>T;
    vector<pair<ll,ll>> v;
    vector<ll> h;
    while(T--) {
        cin>>x>>y;
        w+=x;
        v.pb(mp(x,y));
        h.pb(y);
    }
    sort(all(h));
    n = h.size()-1;
    ll z;
    for(ll i=0;i<v.size();i++) {
        z = h[n];
        if(z==v[i].ss) {
            z = h[n-1];
        }
        cout<<z*(w-v[i].ff)<<" ";
    }
    return 0;
}
