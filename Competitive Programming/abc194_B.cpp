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

ll power(ll x, ll y) {
    ll res = 1;
    while (y > 0) {
        if (y & 1)
            res = res*x;
        y = y>>1;
        x = x*x;
    }
    return res;
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

bool cmp(pair<ll,ll> a,pair<ll,ll> b) {
    return (a.ff+a.ss)<=(b.ff+b.ss);
}

int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //Sieve(1000000);
    ll n;
    cin>>n;
    ll a[n],b[n];
    vector<ll> v;
    vector<pair<ll,ll>> f,l;
    for(ll i=0;i<n;i++) {
        cin>>a[i]>>b[i];
        v.push_back(a[i]+b[i]);
        f.push_back(mpr(a[i],b[i]));
        l.push_back(mpr(b[i],a[i]));
    }
    sort(all(f));
    sort(all(l));
    ll p=*min_element(v.begin(),v.end());
    ll k=f[0].ff,h;
    for(auto g : l) {
        if(g.ss != k) {
            h=g.ff;
            break;
        }
    }
    if(p<max(k,h)) {
            cout<<p<<endll;
    } else  {
        cout<<max(k,h)<<endll;
    }
    return 0;
}
