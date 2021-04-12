#include<bits/stdc++.h>

/*

Pranav Here!!

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

set<ll> prm;

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
  if(!prm.empty()) {
    prm.clear();
  }
  for(ll p=2;p<=n;p++)
  {
    if(prime[p])
    {
      prm.insert(p);
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

#define MOD 998244353

int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //Sieve(1000000);
    ll T,n,q,m,p;
    cin>>T;
    while(T--) {
        cin>>n>>q>>m;
        vector<ll> v(n);
        for(int i=0;i<n;i++) {
            cin>>v[i];
        }
        vector<ll> pref(1000001,0);
        map<pair<ll,ll>,ll> mt;
        while(q--) {
            ll l,r;
            cin>>l>>r;
            if(v[l-1]>m) {
                continue;
            }else if(v[l-1]<=m && v[r-1]>m) {
                pref[v[l-1]]++;
                pref[m+1]--;
            }else if(v[r-1]<=m) {
                pref[v[l-1]]++;
                pref[m+1]--;
                mt[mp(v[l-1],v[r-1])]++;
            }
        }
        for(auto& [key,val] : mt) {
            pref[key.ss+key.ff]-=val;
            pref[key.ss+2*key.ff]+=val;
            p=key.ss+2*key.ff;
            while(p+key.ss<=m) {
                p+=key.ss;
                pref[p]-=val;
                pref[p+key.ff]+=val;
                p+=key.ff;
            }
        }
        ll mx=pref[0];
        for(int i=1;i<=m;i++) {
            pref[i]+=pref[i-1];
            mx=max(mx,pref[i]);
        }
        cout<<mx<<endll;
    }
    return 0;
}
