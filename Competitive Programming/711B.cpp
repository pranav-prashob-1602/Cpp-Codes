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

set<ll> prm;

void Sieve(ll n)
{
  bool prime[n+1];
  memset(prime,true, sizeof(prime));
  for(ll p=2;p*p<=n;p++)
  {
    if(prime[p]==true)
    {
      for(ll i=p*p;i<=n;i+=p)
      {
        prime[i]=false;
      }
    }
  }
  if(!prm.empty()) {
    prm.clear();
  }
  for(ll p=2;p<=n;p++)
  {
    if(prime[p])
    {
      prm.insert(p);
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
    ll n,x,a,b,d1=0,d2=0;
    cin>>n;
    vector<ll> r(n,0),c(n,0);
    for(ll i=0;i<n;i++) {
        for(ll j=0;j<n;j++) {
            cin>>x;
            if(i==j) {
                d1+=x;
            }
            if(i==n-j-1) {
                d2+=x;
            }
            c[j]+=x;
            r[i]+=x;
            if(x==0) {
                a=i;
                b=j;
            }
        }
    }
    if(n==1) {
        cout<<1<<endl;
        return 0;
    }
    ll mx = 0;
    for(ll i=0;i<n;i++) {
        mx = max(max(r[i],c[i]),mx);
    }
    ll k = mx - r[a];
    r[a] = mx;
    c[b]+=k;
    if(a==b) {
        d1+=k;
    }
    if(a==n-b-1) {
        d2+=k;
    }
    bool flag = true;
    for(ll i=0;i<n;i++) {
        flag&=(r[i]==mx && c[i]==mx);
    }
    if(!flag || k<=0 || d1!=mx || d2!=mx) {
        cout<<-1<<endl;
    }else {
        cout<<k<<endl;
    }
    return  0;
}
