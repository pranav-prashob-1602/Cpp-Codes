#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

int main() {
    ll T,n,m,x1,x2,y1,y2;
    cin>>T;
    while(T--) {
        cin>>n;
        ll a[n];
        map<ll,ll> m;
        for(int i=0;i<n;i++) {
            cin>>a[i];
            m[a[i]]++;
        }
        ll val = -1;
        for(auto& it : m) {
            if(it.second==1) {
                if(val == -1) {
                    val = it.first;
                }else {
                    val = min(val,it.first);
                }
            }
        }
        if(val==-1) {
            cout<<val<<endl;
            continue;
        }
        for(ll i=0;i<n;i++) {
            if(val==a[i]) {
                cout<<i+1<<endl;
                break;
            }
        }
    }
    return 0;
}


