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
    ll T,n,k;
    cin>>T;
    while(T--) {
        cin>>n>>k;
        string s;
        cin>>s;
        ll w=0,z=0;
        bool flag = true;
        ll g=0;
        vector<ll> gap;
        for(int i=0;i<n;i++) {
            if(s[i]=='W') {
                if(i==0 || s[i-1]=='L') {
                    z++;
                }
                if(g>0 && w>0) {
                    gap.pb(g);
                }
                g=0;
                w++;
            }else {
                g++;
            }
        }
        if(k+w>=n) {
            cout<<2*n-1<<endll;
            continue;
        }
        //cout<<'Z'<<z<<endll;
        if(k==0) {
            cout<<2*w-z<<endll;
            continue;
        }
        if(w==0) {
            cout<<2*k-1<<endll;
            continue;
        }
        w+=k;
        sort(all(gap));
        for(auto& val : gap) {
            if(val>k) {
                break;
            }
            k-=val;
            z--;
        }
        cout<<2*w-z<<endll;
    }
    return 0;
}

