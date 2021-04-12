#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

int main() {
    ll T,n,m,x;
    cin>>T;
    while(T--) {
        cin>>n>>m;
        vector<ll> v;
        for(ll i=0;i<n;i++) {
            cin>>x;
            v.push_back(x);
        }
        sort(v.begin(),v.end());
        x = v[0];
        ll y,res=0;
        for(ll i=1;i<n;i++) {
            y = m-v[i];
            res+=(y/x);
        }
        cout<<res<<endl;
    }
    return 0;
}


