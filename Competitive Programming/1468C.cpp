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


bool cmp_ind(pair<ll,ll> a,pair<ll,ll> b) {
    return a.f < b.f;
}

bool cmp_m(pair<ll,ll> a,pair<ll,ll> b) {
    if(a.s==b.s) {
        return a.f < b.f;
    }
    return a.s > b.s;
}

int main() {
    ll T,n,x,y;
    cin>>T;
    vector<pair<ll,ll>> v;
    ll k = 0;
    for(int i=0;i<T;i++) {
        cin>>n;
        if(n==1) {
            k++;
            cin>>y;
            v.pb(mp(k,y));
        }else {
            if(n==2) {
                sort(v.begin(),v.end(),cmp_ind);
            }else {
                sort(v.begin(),v.end(),cmp_m);
            }
            cout<<v[0].f<<" ";
            v.erase(v.begin());
        }
    }
    return 0;
}


