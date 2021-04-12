#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

int main() {
    ll T,n,x;
    cin>>T;
    while(T--) {
        cin>>n;
        vector<ll> v;
        for(int i=0;i<n;i++) {
            cin>>x;
            v.push_back(x);
        }
        ll res = 0;
        for(int i=0;i<n-1;i++) {
            res+=max(0LL,v[i]-v[i+1]);
        }
        cout<<res<<endl;
    }
    return 0;
}


