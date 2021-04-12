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
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll T,n,x,sum;
    cin>>T;
    while(T--) {
        cin>>n;
        vector<ll> v;
        sum=0;
        for(ll i=0;i<n;i++) {
            cin>>x;
            sum+=x;
            v.pb(x);
        }
        ll res = 0;
        for(ll k=0;k<n;k++) {
            ll z = sum/(n-k);
            ll s=0;
            for(ll i=0;i<n;i++) {
                s+=v[i];
                if(s==z) {
                    s=0;
                }else if(s>z) {
                    break;
                }
            }
            if(s==0) {
                res = k;
                break;
            }
        }
        cout<<res<<endl;
    }
    return 0;
}


