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

#define mod 1000000007

ll root(ll a,ll x) {
    ll cnt = 0;
    while(a>0) {
        if(a%x==0) {
            a/=x;
            cnt++;
        }else {
            break;
        }
    }
    return cnt+1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll T,n,k,x;
    cin>>T;
    while(T--) {
        cin>>n>>k;
        vector<ll> v;
        for(ll i=0;i<n;i++) {
            cin>>x;
            v.pb(x);
        }
        vector<ll> r;
        ll ind = -1;
        ll ma = INT_MAX;
        for(ll i=0;i<n;i++) {
            ll z = root(v[i],k);
            r.pb(z);
            if(ma>z) {
                ma = z;
                ind = i;
            }
        }
        ll sum = 0,s;
        for(ll i=0;i<n;i++) {
            if(i<=ind) {
                s = v[i]*min(r[i],ma+1);
            }else {
                s = v[i]*min(r[i],ma);
            }
            sum+=s;
        }
        cout<<sum<<endl;
    }
    return 0;
}


