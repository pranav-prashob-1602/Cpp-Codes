#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

int main() {
    ll n,x,m,y;
    cin>>n;
    vector<ll> v;
    m=n;
    y=0;
    while(m--) {
        cin>>x;
        v.push_back(x);
        y+=x;
    }
    x=0;
    sort(v.begin(),v.end(),greater<int> ());
    for(int i=0;i<(n+1)/2;i++) {
        x+=v[i];
    }
    y-=x;
    ll res = y*y + x*x;
    cout<<res;
    return 0;
}



