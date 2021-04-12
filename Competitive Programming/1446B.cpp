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

set<ll> res;

void Sieve(ll n)
{
  bool prime[n+1];
  memset(prime,true, sizeof(prime));
  for(ll p=2;p*p<=n;p++)
  {
    if(prime[p]==true)
    {
      for(ll i=p*p;i<=n;i+=p)
      {
        prime[i]=false;
      }
    }
  }
  if(!res.empty()) {
    res.clear();
  }
  for(ll p=2;p<=n;p++)
  {
    if(prime[p])
    {
      res.insert(p);
    }
  }
}

int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //Sieve(1000000);
    ll n,m;
    string s1,s2;
    cin>>n>>m>>s1>>s2;
    ll dp[n+1][m+1];
    for(ll i=0;i<=n;i++) {
        for(ll j=0;j<=m;j++) {
            if(i==0 || j==0) {
                dp[i][j]=0;
            }
        }
    }
    ll res=0;
    for(ll i=1;i<=n;i++) {
        for(ll j=1;j<=m;j++) {
            dp[i][j] = max(dp[i-1][j],dp[i][j-1])-1<0 ? 0 : max(dp[i-1][j],dp[i][j-1])-1;
            if(s1[i-1]==s2[j-1]) {
                dp[i][j]=max(dp[i][j],2+dp[i-1][j-1]);
            }
            res=max(res,dp[i][j]);
        }
    }
    /*ll sum=0;
    for(ll i=0;i<=n;i++) {
        sum=0;
        for(ll j=0;j<=m;j++) {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    for(ll i=1;i<=n;i++) {
        sum=0;
        for(ll j=1;j<=m;j++) {
            sum+=dp[i][j];
        }
        res=max(res,sum);
    }*/
    cout<<res;
    return 0;
}

