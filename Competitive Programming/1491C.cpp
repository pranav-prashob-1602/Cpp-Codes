#include<bits/stdc++.h>

/*

shinchanCoder Here!!

*/

using namespace std;

#define endll "\n"
#define pb push_back
#define all(x) begin(x), end(x)
#define allr(x) rbegin(x), rend(x)
#define forn(i,n) for(ll i=0;i<(n);i++)

#define sz(x) (int)(x).size()

#define ff first
#define ss second

#define mpr make_pair

#define len(x) x.length()

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
    ll T,i,n,x;
    cin>>T;
    while(T--) {
        cin>>n;
        vector<ll> v;
        forn(i,n) {
            cin>>x;
            v.pb(x);
        }
        ll res=INT_MIN,cs=0;
        forn(i,n) {
            cs=0;
            forn(j,i+1) {
                cs+=max(0LL,v[j]-max(1LL,i-j));
            }
            res=max(res,cs);
        }
        cout<<res<<endll;
    }
    return 0;
}


/*

        vector<ll> dp(n+1,0);
        for(ll i=0;i<n;i++) {
            for(ll j=i+2;j<n && j<v[i]+i+1;j++) {
                dp[j]++;
            }
        }
        for(ll i=0;i<n;i++) {
            dp[i+1]+=max(0LL,dp[i]-v[i]+1);
        }
        ll res=0;
        forn(i,n) {
            res+=max(0LL,v[i]-dp[i]-1);
        }
        cout<<res<<endll;*/
