#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

int main() {
    ll T,n,k;
    cin>>T;
    while(T--) {
        cin>>n>>k;
        vector<ll> v(n);
        ll max_val = 0;
        map<ll,ll> cnt;
        for(auto& it : v) {
            cin>>it;
            if(it%k!=0) {
                cnt[k-it%k]++;
                max_val = max(max_val,cnt[k-it%k]);
            }
        }
        ll res = 0;
        for(auto& it : cnt) {
            if(it.second == max_val) {
                res = k*(max_val-1) + it.first + 1;
            }
        }
        cout<<res<<endl;
    }
    return 0;
}

