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

void BFS(vector<ll> g[],bool vis[],ll ind) {
    queue<ll> q;
    q.push(ind);
    vis[ind]=true;
    while(!q.empty()) {
        ll s=q.front();
        q.pop();
        for(auto& val : g[s]) {
            if(!vis[val]) {
                vis[val]=true;
                q.push(val);
            }
        }
    }
}

ll BFSHelper(vector<ll> g[],ll n) {
    bool vis[n];
    ll cnt=0;
    memset(vis,false,sizeof(vis));
    for(ll i=0;i<n;i++) {
        if(!vis[i]) {
            cnt++;
            BFS(g,vis,i);
        }
    }
    return cnt;
}

void solve() {
    ll n,m,x,y;
    cin>>n>>m;
    vector<ll> g[n];
    for(ll i=0;i<m;i++) {
        cin>>x>>y;
        g[x].pb(y);
        g[y].pb(x);
    }
    cout<<BFSHelper(g,n)-1;
}

int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //Sieve(1000000);
    solve();
    return 0;
}

