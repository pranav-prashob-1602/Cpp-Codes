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
    ll n,m,k;
    char ch;
    cin>>n>>m>>k;
    char s[n][m];
    for(ll i=0;i<n;i++) {
        for(ll j=0;j<m;j++) {
            cin>>ch;
            s[i][j]=ch;
        }
    }
    ll a[n]={0};
    ll b[m]={0};
    for(ll i=0;i<n;i++) {
        ll cnt=0,res=0;
        for(ll j=0;j<m;j++) {
            if(s[i][j]=='.') {
                cnt++;
                if(cnt>=k) {
                    res++;
                    cnt--;
                }
            }else {
                if(cnt>=k) {
                    res++;
                }
                cnt=0;
            }
        }
        a[i]=res;
    }
    for(ll i=0;i<m;i++) {
        ll cnt=0,res=0;
        for(ll j=0;j<n;j++) {
            if(s[j][i]=='.') {
                cnt++;
                if(cnt>=k) {
                    res++;
                    cnt--;
                }
            }else {
                if(cnt>=k) {
                    res++;
                }
                cnt=0;
            }
        }
        b[i]=res;
    }
    ll res=0;
    for(ll i=0;i<n;i++) {
        res+=a[i];
    }
    for(ll i=0;i<m;i++) {
        res+=b[i];
    }
    if(k==1) {
        res/=2;
    }
    cout<<res;
    return  0;
}


