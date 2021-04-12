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

bool cmp(pair<ll,ll> a, pair<ll,ll> b) {
    return a.s < b.s;
}

int main() {
    ll T,a,b,n,cnt;
    cin>>T;
    vector<pair<ll,ll>> v;
    while(T--) {
        cin>>a>>b;
        v.pb(mp(a,b));
    }
    sort(v.begin(),v.end(),& cmp);
    ll ed = -1;
    cnt = 0;
    for(auto& p : v) {
        if(p.f>=ed) {
            cnt++;
            ed = p.s;
        }
    }
    cout<<cnt;
    return 0;
}


