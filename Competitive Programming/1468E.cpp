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
    ll T,n,x,m;
    cin>>T;
    while(T--) {
        vector<ll> v;
        for(int i=0;i<4;i++) {
            cin>>x;
            v.pb(x);
        }
        sort(all(v));
        cout<<v[0]*v[2]<<endl;
    }
    return 0;
}


