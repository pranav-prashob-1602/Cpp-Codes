#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

int main() {
    ll T,n,k,x;
    cin>>T;
    while(T--) {
        cin>>n>>k;
        ll m = n/2;
        vector<ll> v;
        for(ll i=0;i<n*k;i++) {
            cin>>x;
            v.push_back(x);
        }
        //sort(v.begin(),v.end());
        ll cnt = 0,sum=0,ans=0;
        for(ll i = n*k-1;i>=0;i--) {
            if(m==cnt && ans<k) {
                //cout<<v[i]<<" ";
                sum+=v[i];
                ans++;
                cnt = 0;
                continue;
            }
            cnt++;
        }
        cout<<sum<<endl;
    }
    return 0;
}
/*
165
108
145
234
11
3
*/
