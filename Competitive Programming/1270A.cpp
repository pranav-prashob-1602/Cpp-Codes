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

void solve(vector<ll> v,ll left,ll right,ll lvl,map<ll,ll> &mp) {
    if(left>right) {
        return;
    }
    if(left==right) {
        mp[v[left]]=lvl;
    }
    ll mx = v[left];
    ll ind = left;
    for(ll i=left;i<=right;i++) {
        if(mx<v[i]) {
            mx=v[i];
            ind=i;
        }
    }
    mp[v[ind]]=lvl;
    solve(v,left,ind-1,lvl+1,mp);
    solve(v,ind+1,right,lvl+1,mp);
}

int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //Sieve(1000000);
    ll T,n,x,k1,k2;
    cin>>T;
    while(T--) {
        cin>>n>>k1>>k2;
        ll mx1=-1,mx2=-1;
        for(ll i=0;i<k1;i++) {
            cin>>x;
            mx1=max(mx1,x);
        }
        for(ll i=0;i<k2;i++) {
            cin>>x;
            mx2=max(mx2,x);
        }
        if(mx1>mx2) {
            cout<<"YES"<<endll;
        }else {
            cout<<"NO"<<endll;
        }
    }
    return  0;
}

