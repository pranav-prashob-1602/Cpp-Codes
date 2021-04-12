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
    ll n = 6;
    ll coins[n] = {1,2,5,10,50,100};
    ll T,amt;
    cin>>T;
    while(T--) {
        cin>>amt;
        ll dp[n+1][amt+1];
        for(ll i=0;i<=n;i++) {
            for(ll j=0;j<=amt;j++) {
                if(j==0) {
                    dp[i][j] = 0;
                }
                if(i==0) {
                    dp[i][j] = INT_MAX - 1;
                }
            }
        }
        for(ll i=1;i<=amt;i++) {
            dp[1][i] = i;
        }
        for(ll i=2;i<=n;i++) {
            for(ll j=1;j<=amt;j++) {
                if(coins[i-1]<=j) {
                    dp[i][j] = min(dp[i][j-coins[i-1]]+1,dp[i-1][j]);
                }else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        ll res = dp[n][amt]==INT_MAX-1 ? -1 : dp[n][amt];
        cout<<res<<endl;
    }
    return 0;
}


