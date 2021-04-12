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

ll solve(ll n,ll e,ll h,ll a,ll b,ll c) {
    vector<ll> v,v2;
    ll res=INT_MAX,temp,i1,i2,k;
    for(ll i=0;i<=n+1;i++) {
        v.pb(i);
    }
    for(ll j=0;j<=n;j++) {
        i1=lower_bound(all(v),2*n-(e+2*j))-v.begin();
        i2=upper_bound(all(v),h-3*j)-v.begin()-1;
        if(i2==n+1 && i2+3*j>h) {
            continue;
        }
        if(i2<i1 || i1==n+1) {
            continue;
        }
        if(c>a) {
            if(i1<(n-j)) {
                k=i1;
            }else {
                k=n-j;
            }
        }else {
            if(i2<(n-j)) {
                k=i2;
            }else {
                k=n-j;
            }
        }
        temp=n-k-j;
        if(k+2*j>=2*n-e && k+3*j<=h) {
            v2.pb(a*temp+b*j+c*k);
        }
    }
    if(v2.size()==0) {
        return -1;
    }
    res=v2[0];
    for(auto& val : v2) {
        res=min(res,val);
    }
    return res;
}

int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //Sieve(1000000);
    ll T,n,x,e,h,a,b,c;
    cin>>T;
    while(T--) {
        cin>>n>>e>>h>>a>>b>>c;
        cout<<solve(n,e,h,a,b,c)<<endll;
    }
    return 0;
}
