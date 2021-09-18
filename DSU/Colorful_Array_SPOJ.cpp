#include<bits/stdc++.h>
#include<algorithm>
#include<unordered_map>
#include<vector>
#include<unordered_set>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<map>
#include<chrono>

/*

shinchanCoder Here!!

*/

using namespace std;
using namespace chrono;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

#define endll "\n"
#define pb push_back
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define all(x) begin(x), end(x)
#define allr(x) rbegin(x), rend(x)

#define sz(x) (ll)(x).size()
#define pr(x,y) pair<x,y>

#define ff first
#define ss second

#define mpr make_pair

#define len(x) x.length()

#define ll long long
#define ld long double
#define lli long long int

#define ull unsigned long long
#define uld unsigned long double
#define ulli unsigned long long int

#define mod 1000000007
#define PI 3.141592653589793238462

void _google(ll f) {cout<<"Case #"<<f<<": ";}

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(ld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}


ll powmod(ll a, ll b){
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
    prime[0]=false;
    prime[1]=false;
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

ll facCount(ll n) {
    ll cnt=0;
    for(ll i=0;prm[i]*prm[i]<=n && i<prm.size();i++) {
        while(n%prm[i]==0) {
            cnt++;
            n/=prm[i];
        }
    }
    cnt+=(n>1);
    return cnt;
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

class DSU {

    vector<int> p;

public:

    void init(ll n) {
        p.resize(n);
        iota(all(p), 0);
    }

    //DSU FUNCTIONS

    ll findParent(ll u) {
        if(p[u]==u) {
            return u;
        }else {
            return p[u]=findParent(p[u]);
        }
    }

    void unionByRank(ll u, ll v) {
        u=findParent(u);
        v=findParent(v);
        if(u!=v) {
            p[u]=max(p[u], p[v]);
            p[v]=max(p[u], p[v]);
        }
    }

};

void shinchan() {
    ll n,q,l,r,c;
    cin>>n>>q;
    vector<pr(pr(ll,ll), ll)> v;
    while(q--) {
        cin>>l>>r>>c;
        v.pb(mpr(mpr(l-1,r-1), c));
    }

    vector<ll> res(n+1, 0);

    DSU G;
    G.init(n+1);
    for(ll i=v.size()-1;i>=0;i--) {
        ll ind = G.findParent(v[i].ff.ff);

        while(ind<=v[i].ff.ss) {
            res[ind]=v[i].ss;
            G.unionByRank(ind, ind+1);
            ind=G.findParent(ind);
        }
    }

    for(ll i=0;i<n;i++) {
        cout<<res[i]<<endll;
    }
}


int main() {
    fastio();
#ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
    freopen("Error.txt", "w", stderr);
#endif
    auto start1 = high_resolution_clock::now();
    shinchan();
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);
#ifndef ONLINE_JUDGE
    cerr << "Time: " << duration.count() / 1000 << endl;
#endif
    return 0;
}
