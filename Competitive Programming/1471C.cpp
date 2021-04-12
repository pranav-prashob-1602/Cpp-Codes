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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll T,n,m,x;
    cin>>T;
    while(T--) {
        cin>>n>>m;
        vector<ll> v;
        for(ll i=0;i<n;i++) {
            cin>>x;
            v.pb(x);
        }
        sort(all(v),greater<int> ());
        vector<ll> c;
        for(ll i=0;i<m;i++) {
            cin>>x;
            c.pb(x);
        }
        ll f=0,sum=0;
        for(ll i=0;i<n;i++) {
            if(c[v[i]-1]>c[f] && f<m) {
                sum+=c[f];
                f++;
            }else {
                sum+=c[v[i]-1];
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}


