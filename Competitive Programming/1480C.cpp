#include<bits/stdc++.h>

/*

Pranav Here!!

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
    ll n,q;
    cin>>n;
    q=n;
    vector<ll> v;
    ll k=0;
    while(q--) {
        ll x;
        cin>>x;
        v.pb(x);
        cout<<'?'<<" "<<k+1<<"\n";
        cout.flush();
        k++;
    }
    vector<pair<char,ll>> g;
    vector<pair<char,ll>> h;
    g.pb(mp('?',1));
    for(int i=1;i<n;i++){
        if(v[i]<min(v[i-1],v[i+1])){
            g.pb(mp('?',i+1));
            h.pb(mp('!',i+1));
        }else{
            g.pb(mp('?',i+1));
        }
    }
    sort(all(g));
    for(auto& d : h) {
        cout<<d.ff<<" "<<d.ss<<endl;
    }
    cout.flush();
    return 0;
}
