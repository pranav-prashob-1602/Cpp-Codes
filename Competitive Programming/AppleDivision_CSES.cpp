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

ll min_diff(vector<ll> v,ll sum,ll tot,ll i) {
    if(i==0) {
        return abs((tot-sum)-sum);
    }
    return min(min_diff(v,sum+v[i],tot,i-1),min_diff(v,sum,tot,i-1));
}

int main() {
    ll n,x,tot=0;
    vector<ll> v;
    cin>>n;
    for(ll i=0;i<n;i++) {
        cin>>x;
        v.pb(x);
        tot+=x;
    }
    cout<<min_diff(v,0,tot,n-1);
    return 0;
}


