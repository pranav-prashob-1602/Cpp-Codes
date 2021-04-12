#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

int main() {
    ll n,k,x,cnt;
    map<ll,ll> m,p;
    cin>>n>>k;
    for(int i=1;i<=n;i++) {
        cin>>x;
        m[i] = x;
        p[x] = i;
    }
    for(int i=1;i<=n;i++) {
        if(p[m[i]]!=0 && p[k - m[i]] != 0 && i != p[k-m[i]]) {
            cout<<i<<" "<<p[k-m[i]];
            return 0;
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
    return 0;
}


