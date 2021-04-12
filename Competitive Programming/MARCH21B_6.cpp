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

vector<ll> xv1,xv2;

bool solve(ll x,ll y) {
    bool flag=false;
    for(ll i=0;i<xv1.size();i++) {
        flag|=(xv2[i]>=x && xv1[i]<=y);
        if(flag) {
            return flag;
        }
    }
    return flag;
}

ll solveGraph() {
    ll n,m,p,q,r,s,x,y;
    cin>>n>>m>>x>>y;
    vector<ll> a(m),b(m),c(m),d(m);
    for(ll i=0;i<m;i++) {
        cin>>p>>q>>r>>s;
        a[i]=p;
        b[i]=q;
        c[i]=r;
        d[i]=s;
    }
    if(x==y) {
        return 0;
    }
    ll dfs[m]={0};
    ll res=-1,cnt=0;
    vector<ll> v1,v2;
    v1.pb(x);
    v2.pb(x);
    while(res==-1 && v1.size()!=0) {
        xv1.clear();
        xv2.clear();
        xv1=v1;
        xv2=v2;
        vector<ll> h,g;
        for(ll i=0;i<m;i++) {
            if(dfs[i]==0 && solve(a[i],b[i])) {
                g.pb(d[i]);
                h.pb(c[i]);
                if(d[i]>=y && c[i]<=y) {
                    res=cnt+1;
                }
                dfs[i]=1;
            }
        }
        v1=h,v2=g;
        cnt++;
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
    ll T;
    cin>>T;
    while(T--) {
        cout<<solveGraph()<<endll;
    }
    return 0;
}
