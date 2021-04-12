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
    ll T;
    cin>>T;
    while(T--) {
        ll v[9][9];
        char ch;
        for(ll i=0;i<9;i++) {
            for(ll j=0;j<9;j++) {
                cin>>ch;
                v[i][j]=ch-'0';
                if(i==0 && j==0) {
                    v[i][j]--;
                    if(v[i][j]==0) {
                        v[i][j]+=2;
                    }
                }else if(i==1 && j==3) {
                    v[i][j]--;
                    if(v[i][j]==0) {
                        v[i][j]+=2;
                    }
                }else if(i==2 && j==6) {
                    v[i][j]--;
                    if(v[i][j]==0) {
                        v[i][j]+=2;
                    }
                }else if(i==3 && j==1) {
                    v[i][j]--;
                    if(v[i][j]==0) {
                        v[i][j]+=2;
                    }
                }else if(i==4 && j==4) {
                    v[i][j]--;
                    if(v[i][j]==0) {
                        v[i][j]+=2;
                    }
                }else if(i==5 && j==7) {
                    v[i][j]--;
                    if(v[i][j]==0) {
                        v[i][j]+=2;
                    }
                }else if(i==6 && j==2) {
                    v[i][j]--;
                    if(v[i][j]==0) {
                        v[i][j]+=2;
                    }
                }else if(i==7 && j==5) {
                    v[i][j]--;
                    if(v[i][j]==0) {
                        v[i][j]+=2;
                    }
                }else if(i==8 && j==8) {
                    v[i][j]--;
                    if(v[i][j]==0) {
                        v[i][j]+=2;
                    }
                }
                cout<<v[i][j];
            }
            cout<<endl;
        }
    }
    return  0;
}

