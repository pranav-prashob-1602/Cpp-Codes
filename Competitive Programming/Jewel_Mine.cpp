#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) begin(x), end(x)

#define sz(x) (int)(x).size()

#define ff first
#define ss second

#define mp make_pair

#define ll long long
#define ld long double

#define mod 1000000007

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n,x,z,T,m,cnt;
    cin>>T;
    while(T--) {
        cin>>n>>m;
        cnt=0;
        for(ll i=1;i<=n;i++) {
            cnt+= i%2 ? 0 : i;
        }
        z = pow(m,cnt);
        z = z%mod;
        cout<<z<<endl;
    }
    return 0;
}



