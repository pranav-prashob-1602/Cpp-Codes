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
    ll n,res=0;
    cin>>n;
    vector<ll> v(n);
    for(ll i=0;i<n;i++) {
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    ll x = v[n/2];
    for(ll i=0;i<n;i++) {
        res+=abs(v[i]-x);
    }
    cout<<res;
    return 0;
}


