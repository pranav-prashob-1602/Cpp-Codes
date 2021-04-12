#include<bits/stdc++.h>

/*

shinchanCoder Here!!

*/

using namespace std;

#define pb push_back
#define all(x) begin(x), end(x)

#define sz(x) (int)(x).size()

#define ff first
#define ss second

#define mp make_pair

#define ll long long
#define ld long double

#define mod 1000000007

set<ll> res;

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
  if(!res.empty()) {
    res.clear();
  }
  for(ll p=2;p<=n;p++)
  {
    if(prime[p])
    {
      res.insert(p);
    }
  }
}

int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //Sieve(1000000);
    ll T,n,m,x;
    cin>>T;
    while(T--) {
        cin>>n;
        vector<ll> v,u;
        for(ll i=0;i<n;i++) {
            cin>>x;
            v.pb(x);
        }
        for(ll i=0;i<n;i++) {
            cin>>x;
            u.pb(x);
        }
        ll a[n] = {0};
        m=0;
        for(ll i=0;i<n;i++) {
            if(v[i]!=u[i]) {
                ll j=0;
                ll d = u[i] - v[i];
                if(d<0) {
                    m=2;
                    break;
                }
                while(v[i+j]!=u[i+j] && u[i+j]-v[i+j]==d) {
                    j++;
                }
                a[m] = j;
                i = i+j-1;
                m++;
            }
        }
        if(m>1) {
            cout<<"NO"<<endl;
        }else {
            cout<<"YES"<<endl;
        }
    }
    return 0;
}
