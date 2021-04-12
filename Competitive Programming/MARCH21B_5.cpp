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

ll A[1001][1001],B[1001][1001];

bool isSame(ll n,ll m) {
    bool flag=true;
    for(ll i=0;i<n;i++) {
        for(ll j=0;j<m;j++) {
            flag&=(A[i][j]==B[i][j]);
        }
    }
    return flag;
}

bool solve() {
    ll n,m,k,x;
    cin>>n>>m>>k;
    for(ll i=0;i<n;i++) {
        for(ll j=0;j<m;j++) {
            cin>>A[i][j];
        }
    }
    for(ll i=0;i<n;i++) {
        for(ll j=0;j<m;j++) {
            cin>>B[i][j];
        }
    }
    if(k>n && k>m) {
        return isSame(n,m);
    }else if(k>n) {
        for(ll i=0;i<n;i++) {
            for(ll j=0;j<m-k+1;j++) {
                if(A[i][j]!=B[i][j]) {
                    ll diff=B[i][j]-A[i][j];
                    A[i][j]=B[i][j];
                    x=1;
                    while(x<k) {
                        A[i][j+x]+=diff;
                        x++;
                    }
                }
            }
        }
    }else if(k>m) {
        for(ll j=0;j<m;j++) {
            for(ll i=0;i<n-k+1;i++) {
                if(A[i][j]!=B[i][j]) {
                    ll diff=B[i][j]-A[i][j];
                    A[i][j]=B[i][j];
                    x=1;
                    while(x<k) {
                        A[i+x][j]+=diff;
                        x++;
                    }
                }
            }
        }
    }else {
        for(ll i=0;i<n;i++) {
            for(ll j=0;j<m-k+1;j++) {
                if(A[i][j]!=B[i][j]) {
                    ll diff=B[i][j]-A[i][j];
                    A[i][j]=B[i][j];
                    x=1;
                    while(x<k) {
                        A[i][j+x]+=diff;
                        x++;
                    }
                }
            }
        }
        for(ll j=0;j<m;j++) {
            for(ll i=0;i<n-k+1;i++) {
                if(A[i][j]!=B[i][j]) {
                    ll diff=B[i][j]-A[i][j];
                    A[i][j]=B[i][j];
                    x=1;
                    while(x<k) {
                        A[i+x][j]+=diff;
                        x++;
                    }
                }
            }
        }
    }
    return isSame(n,m);
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
        if(solve()) {
            cout<<"Yes"<<endll;
        }else {
            cout<<"No"<<endll;
        }
    }
    return 0;
}
