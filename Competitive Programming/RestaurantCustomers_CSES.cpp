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
    ll T,a,b,res=0;
    vector<pair<ll,ll>> v;
    cin>>T;
    while(T--) {
        cin>>a>>b;
        v.pb(mp(a,1));
        v.pb(mp(b,-1));
    }
    sort(all(v));
    ll sum = 0;
    for(auto& it : v) {
        sum+=it.s;
        res = max(res,sum);
    }
    cout<<res;
    return 0;
}


