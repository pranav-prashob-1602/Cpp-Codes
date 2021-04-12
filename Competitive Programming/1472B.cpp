#include<bits/stdc++.h>

/*

shinchanCoder Here!!

*/

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
    ll T,n,x;
    cin>>T;
    while(T--) {
        cin>>n;
        vector<ll> v;
        ll sum =0;
        for(ll i=0;i<n;i++) {
            cin>>x;
            sum+=x;
            v.pb(x);
        }
        if(sum%2) {
            cout<<"NO"<<endl;
            continue;
        }
        sum/=2;
        bool dp[n+1][sum+1];
        for(ll i=0;i<=n;i++) {
            for(ll j=0;j<=sum;j++) {
                if(i==0) {
                    dp[i][j] = false;
                }
                if(j==0) {
                    dp[i][j] = true;
                }
            }
        }
        for(ll i=1;i<=n;i++) {
            for(ll j=1;j<=sum;j++) {
                if(v[i-1]<=j) {
                    dp[i][j] = dp[i-1][j-v[i-1]] || dp[i-1][j];
                }else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        if(dp[n][sum]) {
            cout<<"YES"<<endl;
        }else {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
