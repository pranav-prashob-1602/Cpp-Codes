#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

int main() {
    ll T,n,x;
    cin>>T;
    while(T--) {
        cin>>n;
        vector<ll> a;
        for(ll i =0;i<n;i++) {
            cin>>x;
            a.push_back(x);
        }
        sort(a.begin(),a.end());
        ll ans = a[0]*a[1]*a[2]*a[3]*a[4];
        ans = max(ans,a[0]*a[1]*a[2]*a[3]*a[n-1]);
        ans = max(ans,a[0]*a[1]*a[2]*a[n-2]*a[n-1]);
        ans = max(ans,a[0]*a[1]*a[n-3]*a[n-2]*a[n-1]);
        ans = max(ans,a[0]*a[n-4]*a[n-3]*a[n-2]*a[n-1]);
        ans = max(ans,a[n-5]*a[n-4]*a[n-3]*a[n-2]*a[n-1]);
        cout<<ans<<endl;
    }
    return 0;
}



