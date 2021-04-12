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

int p[2000];

int parent(int x) {
    if(p[x]==x) {
        return x;
    }
    return p[x] = parent(p[x]);
}

int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //Sieve(1000000);
    ll n,x;
    cin>>n;
    vector<ll> v;
    for(ll i=0;i<n;i++) {
        cin>>x;
        v.pb(x);
    }
    vector<ll> dp(n,0);
    for(ll i=1;i<n;i++) {
        if(v[i]>0) {
            if(v[i-1]>0) {
                dp[i] = dp[i-1]+v[i];
                dp[i-1]=0;
            }else {
                dp[i]+= v[i];
            }
        }else {
            dp[i] = 0;
        }
    }
    sort(all(dp));
    sort(all(v));
    if(dp[n-1]+dp[n-2]==0) {
        cout<<v[n-1]+v[n-2];
    }else {
        cout<<dp[n-1]+dp[n-2];
    }
    return 0;
}

