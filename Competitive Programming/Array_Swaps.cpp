#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) begin(x), end(x)

#define sz(x) (int)(x).size()

#define f first
#define s second

#define mp make_pair

#define ll long long
#define ld long double

int main() {
    ll n,m,x;
    vector<ll> v1,v2;
    cin>>n>>m;
    for(int i=0;i<n;i++) {
        cin>>x;
        v1.pb(x);
    }
    for(int i=0;i<m;i++) {
        cin>>x;
        v2.pb(x);
    }
    sort(v1.begin(),v1.end());
    ll res = 0;
    for(int i=0;i<m;i++) {
        if(v2[i]<v1[0]) {
            res+=n;
        }
    }
    cout<<res<<endl;
    return 0;
}


