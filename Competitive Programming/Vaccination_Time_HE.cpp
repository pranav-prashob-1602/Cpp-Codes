#include<bits/stdc++.h>

/*

shinchanCoder Here!!

*/

using namespace std;

#define endll "\n"
#define pb push_back
#define all(x) begin(x), end(x)
#define allr(x) rbegin(x), rend(x)

#define sz(x) (int)(x).size()

#define ff first
#define ss second

#define mp make_pair

#define ll long long
#define ld long double
#define lli long long int

#define mod 1000000007

ll powmod(ll a,  ll b){
    if(b==0){
        return 1 ;
    }
    ll x = powmod(a,b/2);
    x = (x*x)%mod ;
    if(b%2){
        x = (a*x)%mod ;
    }
    return x;
}

vector<ll> prm;

void Sieve(ll n) {
  bool prime[n+1];
  memset(prime,true, sizeof(prime));
  for(ll p=2;p*p<=n;p++) {
    if(prime[p]==true) {
      for(ll i=p*p;i<=n;i+=p) {
        prime[i]=false;
      }
    }
  }
  if(!prm.empty()) {
    prm.clear();
  }
  for(ll p=2;p<=n;p++) {
    if(prime[p]) {
      prm.pb(p);
    }
  }
}

ll fact(ll n) {
    ll res = 1;
    for(ll i=2;i<=n;i++) {
        res*=i;
    }
    return res;
}

ll _lcm(ll x,ll y) {
    return x*y/__gcd(x,y);
}

ll _gcd(ll a,ll b) {
    if(!a) {
        return b%mod;
    }
    return _gcd((b%a)%mod,a%mod);
}

ll nCr(ll n,ll r) {
    return (ld)fact(n)/(ld)(fact(r)*fact(n-r));
}

int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //Sieve(1000000);
    ll m,n,x,y,a,b,c,d;
    cin>>n>>m;
    int v[n][m],dp[n+1][m+1];
    memset(dp,0,sizeof(dp));
    for(ll i=0;i<n;i++) {
        for(ll j=0;j<m;j++) {
            cin>>v[i][j];
        }
    }
    for(ll i=1;i<=n;i++) {
        for(ll j=1;j<=m;j++) {
            dp[i][j]=dp[i][j-1]+v[i-1][j-1]%2;
        }
    }
    for(ll i=1;i<=m;i++) {
        for(ll j=1;j<=n;j++) {
            dp[j][i]+=dp[j-1][i];
        }
    }
    /*for(ll i=0;i<=n;i++) {
        for(ll j=0;j<=m;j++) {
            cout<<dp[i][j]<<" ";
        }
        cout<<endll;
    }*/
    cin>>x;
    while(x--) {
        cin>>a>>b>>c>>d;
        ll res=dp[c][d]-(dp[a-1][d]+dp[c][b-1])+dp[a-1][b-1];
        cout<<res<<endll;
    }
    return  0;
}

