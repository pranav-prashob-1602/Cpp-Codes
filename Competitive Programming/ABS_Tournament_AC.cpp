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
    ll n,x;
    cin>>n;
    n = pow(2,n);
    vector<ll> v;
    ll mx = -1,ind = 0;
    for(ll i=0;i<n;i++) {
        cin>>x;
        v.pb(x);
        if(x>mx) {
            mx = x;
            ind = i;
        }
    }
    ll res = -1,m=-1;
    if(ind>=n/2) {
        for(ll i=0;i<n/2;i++) {
            if(v[i]>m) {
                m = v[i];
                res = i+1;
            }
        }
    }else {
        for(ll i=n/2;i<n;i++) {
            if(v[i]>m) {
                m = v[i];
                res = i+1;
            }
        }
    }
    cout<<res<<endl;
    return 0;
}
