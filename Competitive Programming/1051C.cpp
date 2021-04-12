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

int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //Sieve(1000000);
    ll n,x;
    map<ll,ll> mp;
    vector<ll> p;
    cin>>n;
    for(ll i=0;i<n;i++) {
        cin>>x;
        p.pb(x);
        mp[x]++;
    }
    vector<ll> v;
    ll z  = -1;
    for(auto& val : mp) {
        if(val.ss==1) {
            v.pb(val.ff);
        }
        if(val.ss>2) {
            z=val.ff;
        }
    }
    if(v.size()%2==0) {
        ll cnt=v.size()/2;
        cout<<"YES"<<endll;
        for(ll i=0;i<n;i++) {
            if(mp[v[i]]==1 && cnt>0) {
                cout<<'A';
                cnt--;
            }else {
                cout<<'B';
            }
        }
    }else {
        if(z==-1) {
            cout<<"NO"<<endll;
        }else {
            cout<<"YES"<<endll;
            ll cnt = v.size()/2;
            for(ll i=0;i<n;i++) {
                if(mp[v[i]]==1 && cnt>0) {
                    cout<<'A';
                    cnt--;
                }else if(v[i]==z) {
                    cout<<'A';
                    z=-1;
                }else {
                    cout<<'B';
                }
            }
        }
    }
    return  0;
}

