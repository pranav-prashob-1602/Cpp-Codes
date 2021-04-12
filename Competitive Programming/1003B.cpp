#include<bits/stdc++.h>

/*

shinchanCoder Here!!

*/

using namespace std;

#define endll "\n"
#define pb push_back
#define all(x) begin(x), end(x)
#define allr(x) rbegin(x), rend(x)

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
    ll a,b,x,n;
    cin>>a>>b>>x;
    string s="";
    n=a+b;
    if(a>b) {
        s+='0';
        a--;
    }else {
        s+='1';
        b--;
    }
    for(ll i=1;i<n;i++) {
        if(x>1) {
            if(s[i-1]=='1' && a>0) {
                s+='0';
                a--;
                x--;
            }else if(s[i-1]=='0' && b>0) {
                s+='1';
                b--;
                x--;
            }
        }else {
            if(s[i-1]=='1' && b>0) {
                s+='1';
                b--;
            }else if(s[i-1]=='1' && b==0) {
                s+='0';
                a--;
            }else if(s[i-1]=='0' && a>0) {
                s+='0';
                a--;
            }else if(s[i-1]=='0' && a==0) {
                s+='1';
                b--;
            }
        }
    }
    cout<<s;
    return  0;
}

