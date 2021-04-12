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
    return a%b==0 ? b : _gcd(b,a%b);
}

ll nCr(ll n,ll r) {
    return (ld)fact(n)/(ld)(fact(r)*fact(n-r));
}

void bfs(vector<ll> g[],ll s,ll pref[],ll n,ll k) {
    bool used[n];
    memset(used,false,sizeof(used));
    queue<ll> q;
    q.push(s);
    ll d[n];
    memset(d,0,sizeof(d));
    used[s]=true;
    while(!q.empty()) {
        ll v=q.front();
        q.pop();
        for(ll u : g[v]) {
            if(!used[u]) {
                used[u]=true;
                q.push(u);
                d[u]=d[v]+1;
            }
        }
    }
    for(ll i=0;i<n;i++) {
        if(d[i]<=k && used[i]) {
            pref[i]++;
        }
        //cout<<d[i]<<" ";
    }
}

void solve() {
    ll n,r,m,x,y;
    cin>>n>>r>>m;
    vector<ll> g[n];
    for(ll i=0;i<r;i++) {
        cin>>x>>y;
        g[x-1].pb(y-1);
        g[y-1].pb(x-1);
    }
    ll pref[n];
    memset(pref,0,sizeof(pref));
    for(ll i=0;i<m;i++) {
        cin>>x>>y;
        if(y==0) {
            pref[x-1]++;
        }else {
            bfs(g,x-1,pref,n,y);
        }
    }
    bool flag=true;
    //cout<<endll;
    for(ll i=0;i<n;i++) {
        //cout<<pref[i]<<" ";
        flag&=(pref[i]==1);
    }
    if(flag) {
        cout<<"Yes"<<endll;
    }else {
        cout<<"No"<<endll;
    }
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
        solve();
    }
    return 0;
}
