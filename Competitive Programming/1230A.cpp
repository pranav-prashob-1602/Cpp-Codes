#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

int main() {
    ll T,n,k;
    T=1;
    while(T--) {
        vector<ll> v;
        for(int i=0;i<4;i++) {
            cin>>n;
            v.push_back(n);
        }
        sort(v.begin(),v.end());
        if(v[0]+v[3] == v[1]+v[2]) {
            cout<<"YES"<<endl;
        }else if(v[0]+v[1]+v[2] == v[3]) {
            cout<<"YES"<<endl;
        }else {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}


