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
    ll T,n,x;
    cin>>T;
    while(T--) {
        cin>>n;
        vector<ll> v;
        for(ll i=0;i<n;i++) {
            cin>>x;
            v.pb(x);
        }
        ll t[n];
        memset(t,0,sizeof(t));
        for(ll i=n-1;i>=0;i--) {
            if(v[i]+i<n) {
                t[i] = t[i+v[i]] + v[i];
            }else {
                t[i] = v[i];
            }
        }
        ll res = max_element(t,t+n)-t;
        cout<<t[res]<<endl;
    }
    return 0;
}
