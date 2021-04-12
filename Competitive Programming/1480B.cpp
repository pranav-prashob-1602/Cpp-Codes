#include<bits/stdc++.h>

/*

shinchanCoder Here!!

*/

using namespace std;

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

bool cmp(pair<ll,ll> a,pair<ll,ll> b) {
    if(a.ff==b.ff) {
        return a.ss<b.ss;
    }
    return a.ff<b.ff;
}

int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //Sieve(1000000);
    ll T,a,b,n,x;
    cin>>T;
    while(T--) {
        cin>>a>>b>>n;
        vector<ll> v,u;
        vector<pair<ll,ll>> p;
        for(ll i=0;i<n;i++) {
            cin>>x;
            v.pb(x);
        }
        for(ll i=0;i<n;i++) {
            cin>>x;
            p.pb(mp(v[i],x));
        }
        sort(all(p));
        ll i;
        bool flag = false;
        for(i=0;i<n;i++) {
            ll z = (p[i].ss+a-1)/a;
            ll y = (b+p[i].ff-1)/p[i].ff;
            if(z<y) {
                y = z;
            }
            if(b-p[i].ff*z>0) {
                b-=p[i].ff*min(z,y);
            }else {
                flag = true;
                if(i==n-1 && b-p[i].ff*(z-1)>0) {
                    flag = false;
                }
                break;
            }
        }
        if(flag) {
            cout<<"NO"<<endl;
        }else {
            cout<<"YES"<<endl;
        }
    }
    return  0;
}
