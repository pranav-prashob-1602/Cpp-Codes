#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

int main() {
    ll T,n,x,k;
    cin>>T;
    while(T--) {
        cin>>n>>k;
        vector<ll> v;
        for(int i=0;i<n;i++) {
            cin>>x;
            v.push_back(x);
        }
        k = min(k,2+k%2);
        while(k--) {
            x = *max_element(v.begin(),v.end());
            for(int i=0;i<n;i++) {
                v[i] = x - v[i];
            }
        }
        for(int i=0;i<n;i++) {
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}


