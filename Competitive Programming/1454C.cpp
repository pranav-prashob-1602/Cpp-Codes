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
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll T,n,x,z=0;
    cin>>T;
    while(T--) {
        cin>>n;
        vector<ll> v;
        for(ll i=0;i<n;i++) {
            cin>>x;
            v.pb(x);
        }
        n = unique(all(v))-v.begin();
        v.resize(n);
        map<ll,ll> m;
        n = v.size();
        for(ll i=0;i<n;i++) {
            m[v[i]]++;
        }
        m[v[0]]--;
        m[v[n-1]]--;
        ll res = INT_MAX;
        for(auto& it : m) {
            res = min(res,it.ss);
        }
        cout<<res+1<<endl;
    }
    return 0;
}


