#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

int main() {
    ll N,x,T;
    cin>>T;
    while(T--) {
        cin>>N;
        vector<ll> v;
        for(int i=0;i<N;i++) {
            cin>>x;
            v.push_back(x);
        }
        sort(v.begin(),v.end());
        if(N<=2) {
            cout<<v[N-1]<<endl;
        }
        else {
            sort(v.begin(),v.end(),greater<int>());
            ll x = v[1];
            ll diff = v[0]-v[1];
            for(int i=2;i<N;i++) {
                ll z = min(v[i],diff);
                diff = abs(diff - v[i]);
                x+=z;
            }
            ll sum  = accumulate(v.begin(),v.end(),0);
            cout<<sum-x<<endl;
        }
    }
    return 0;
}


