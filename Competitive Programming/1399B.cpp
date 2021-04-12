#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

int main() {
    ll T,n,x;
    cin>>T;
    while(T--) {
        cin>>n;
        vector<ll> a,b;
        ll min_a=INT_MAX,min_b = INT_MAX;
        for(int i=0;i<n;i++) {
            cin>>x;
            a.push_back(x);
            min_a = min(min_a,x);
        }
        for(int i=0;i<n;i++) {
            cin>>x;
            b.push_back(x);
            min_b = min(min_b,x);
        }
        ll res = 0;
        for(int i=0;i<n;i++)  {
            res+=max(a[i]-min_a,b[i]-min_b);
        }
        cout<<res<<endl;
    }
    return 0;
}


