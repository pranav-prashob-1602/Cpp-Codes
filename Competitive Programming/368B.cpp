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
    ll n,m,x;
    cin>>n>>m;
    vector<ll> v;
    map<ll,ll> cnt;
    set<ll> s;
    for(ll i=0;i<n;i++) {
        cin>>x;
        v.pb(x);
        cnt[x]++;
        s.insert(x);
    }
    vector<ll> res;
    for(ll i=0;i<n;i++) {
        --cnt[v[i]];
        res.pb(s.size());
        if(cnt[v[i]]==0) {
            s.erase(v[i]);
        }
    }
    while(m--) {
        cin>>x;
        cout<<res[x-1]<<endl;
    }
    return 0;
}
