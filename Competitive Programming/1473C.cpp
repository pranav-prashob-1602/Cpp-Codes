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
    ll T,n,k;
    cin>>T;
    while(T--) {
        cin>>n>>k;
        vector<ll> v;
        ll z=1;
        for(ll i=1;i<=n;i++) {
            v.pb(z);
            if(i<k) {
                z++;
            }else {
                z--;
            }
        }
        if(k!=n) {
            vector<ll> res;
            for(ll i=0;i<2*k-n-1;i++) {
                res.pb(v[i]);
            }
            for(ll i=k-1;i<n;i++) {
                res.pb(v[i]);
            }
            for(ll i=0;i<res.size();i++) {
                cout<<res[i]<<" ";
            }
        }else {
            for(ll i=0;i<n;i++) {
                cout<<v[i]<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}

