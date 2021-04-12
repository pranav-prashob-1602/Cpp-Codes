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
    ll n,x,y,x1,x2,x3,y1,y2,y3;
    vector<pair<ll,ll>> v;
    cin>>n;
    for(ll i=0;i<n;i++) {
        cin>>x>>y;
        v.pb(mp(x,y));
    }
    for(ll i=n-1;i>=0;i--) {
        for(ll j=i-1;j>=0;j--) {
            for(ll k=j-1;k>=0;k--) {
                x1 = v[i].ff;
                y1 = v[i].ss;
                x2 = v[j].ff;
                y2 = v[j].ss;
                x3 = v[k].ff;
                y3 = v[k].ss;
                x1-=x3;
                y1-=y3;
                x2-=x3;
                y2-=y3;
                if(x1*y2 == x2*y1) {
                    cout<<"Yes";
                    return 0;
                }
            }
        }
    }
    cout<<"No";
    return 0;
}
