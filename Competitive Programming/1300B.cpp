#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

int main() {
    ll T,n,m;
    cin>>T;
    while(T--) {
        cin>>n;
        vector<ll> v;
        for(int i=0;i<2*n;i++) {
            cin>>m;
            v.push_back(m);
        }
        sort(v.begin(),v.end());
        // ll x = -1;
        // for(int i=0;i<2*n;i++) {
        //         // ll y = v[i] - v[i-1];
        //         // if(y>x) {
        //         //     x =  y;
        //         // }
        //         cout<<v[i]<<" ";
        // }
        //cout<<x<<endl;
        cout<<v[n]-v[n-1]<<endl;
    }
    return 0;
}


