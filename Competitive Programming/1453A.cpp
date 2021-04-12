#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

int main() {
    ll T,n,m,x,cnt;
    cin>>T;
    while(T--) {
        cin>>n>>m;
        map<ll,ll> mp;
        for(int i=0;i<n;i++) {
            cin>>x;
            mp[x]++;
        }
        for(int i=0;i<m;i++) {
            cin>>x;
            mp[x]++;
        }
        cnt = 0;
        for(auto& x : mp) {
            if(x.second==2) {
                cnt++;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}


