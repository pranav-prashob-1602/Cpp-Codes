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
    ll n,x;
    vector<ll> v;
    cin>>n;
    for(ll i=0;i<n;i++) {
        cin>>x;
        v.pb(x);
    }
    ll res=0,cnt=0;
    for(ll i=0;i<n-1;i++) {
        if(v[i]<=v[i+1]) {
            cnt++;
            res = max(res,cnt);
        }else {
            cnt=0;
        }
    }
    cout<<res+1;
    return 0;
}



