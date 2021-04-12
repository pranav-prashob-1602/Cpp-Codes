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
        cin>>m;
        n = m;
        vector<ll> v;
        while(n--) {
            cin>>x;
            v.pb(x);
        }
        vector<ll> res;
        for(int i=0;i<m-1;i++) {
            res[i] = min(res[i],res[i+1]);
        }
        for(int i=0;i<m-1;i++) {
            if(res[i])
        }
    }
    return 0;
}


