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

int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //Sieve(1000000);
    ll T,n,x,k,q,r;
    cin>>T;
    while(T--) {
        cin>>n>>k;
        vector<ll> v;
        map<ll,ll> mp;
        for(ll i=0;i<n;i++) {
            cin>>x;
            v.pb(x);
            /*q=x/k;
            r=x%k;
            if(v[i]<=k) {
                mp[k-v[i]]++;
            }else {
                if(r!=0) {
                    q++;
                    ll temp=q*k;
                    temp-=x;
                    mp[temp]++;
                }else {
                    mp[0]++;
                }
            }*/
            mp[x%k]++;
        }
        ll cnt=0;
        if(mp[0]>0) {
            cnt++;
            mp[0]=0;
        }
        for(ll i=0;i<k;i++) {
            if(mp[i]>0) {
                if(mp[k-i]>0) {
                    x=min(mp[i],mp[k-i]);
                    ll y=max(mp[i],mp[k-i]);
                    if(i==k-1) {
                        cnt++;
                        mp[i]=0;
                        continue;
                    }
                    cnt++;
                    if(y>x+1) {
                        cnt+=y-x-1;
                    }
                    mp[k-i]=0;
                }else {
                    cnt+=mp[i];
                }
                mp[i]=0;
            }
        }
        cout<<cnt<<endll;
    }
    return 0;
}

