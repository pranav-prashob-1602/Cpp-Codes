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
    ll n,k,x;
    vector<ll> v,res;
    cin>>n>>k;
    for(ll i=0;i<n;i++) {
        cin>>x;
        v.pb(x);
    }
    ll cnt=0;
    res.pb(v[0]);
    for(ll i=1;i<n;i++) {
        if(v[i]+res[i-1]<k) {
            res.pb(k-res[i-1]);
            cnt+=(k-(v[i]+res[i-1]));
        }else {
            res.pb(v[i]);
        }
    }
    cout<<cnt<<endl;
    for(auto& val : res) {
        cout<<val<<" ";
    }
    return 0;
}



