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
    ll n,x;
    map<ll,ll> m;
    vector<ll> v;
    cin>>n;
    for(ll i=0;i<n;i++) {
        cin>>x;
        v.pb(x);
        m[x]++;
    }
    sort(all(v));
    ll res;
    if(v[0]==v[1] && v[1]==v[2]) {
        res = (m[v[0]]*(m[v[1]]-1)*(m[v[2]]-2))/6;
    }else if(v[0]==v[1]) {
        res = (m[v[0]]*(m[v[1]]-1)*m[v[2]])/2;
    }else if(v[1]==v[2]) {
        res = (m[v[0]]*m[v[1]]*(m[v[2]]-1))/2;
    }else {
        res = m[v[0]]*m[v[1]]*m[v[2]];
    }
    cout<<res;
    return 0;
}


