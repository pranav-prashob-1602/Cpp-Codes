#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double



int main() {
    ll N,x,sum=0;
    map<ll,ll> m;
    map<ll,ll>::iterator it;
    cin>>N;
    for(int i=0;i<N;i++) {
        cin>>x;
        m[x]++;
    }
    for(it=m.begin();it!=m.end();it++) {
        ll x = it->second;
        sum+=(x*(x-1))/2;
    }
    cout<<sum;
    return 0;
}


