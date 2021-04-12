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
    int T,n,x;
    cin>>T;
    while(T--) {
        cin>>n;
        vector<int> prc,len;
        for(int i=0;i<n;i++) {
            cin>>x;
            prc.pb(x);
            len.pb(i+1);
        }
        int dp[n+1][n+1];
        for(int i=0;i<=n;i++) {
            for(int j=0;j<=n;j++) {
                if(i==0 || j==0) {
                    dp[i][j] = 0;
                }
            }
        }
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                if(len[i-1]<=j) {
                    dp[i][j] = max(prc[i-1]+dp[i][j-len[i-1]],dp[i-1][j]);
                }else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        cout<<dp[n][n]<<endl;
    }
    return 0;
}
