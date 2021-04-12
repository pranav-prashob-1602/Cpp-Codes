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
    ll n,sum=0,res=INT_MIN;
    cin>>n;
    vector<ll> v(n);
    for(ll i=0;i<n;i++) {
        cin>>v[i];
    }
    for(ll i=0;i<n;i++) {
        sum+=v[i];
        res = max(res,sum);
        sum = max(0LL,sum);
    }
    cout<<res<<endl;
    return 0;
}


