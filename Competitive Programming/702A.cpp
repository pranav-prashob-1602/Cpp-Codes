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
    ll n,x;
    cin>>n;
    vector<ll> v;
    for(int i=0;i<n;i++) {
        cin>>x;
        v.pb(x);
    }
    ll cnt=1,res=1;
    for(int i=0;i<n-1;i++) {
        if(v[i]<v[i+1]) {
            cnt++;
        }else {
            res =max(res,cnt);
            cnt=1;
        }
    }
    res = max(res,cnt);
    cout<<res;
    return 0;
}


