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
    ll T,n,a,b,c,d,p,q,y,x;
    cin>>T;
    while(T--) {
        cin>>n>>a>>b>>c>>d>>p>>q>>y;
        vector<ll> v;
        for(ll i=0;i<n;i++) {
            cin>>x;
            v.pb(x);
        }
        ll A = v[a-1];
        ll B = v[b-1];
        ll C = v[c-1];
        ll D = v[d-1];
        ll res = (B-A)*p;
        x = abs(C-A)*p;
        if(x>y) {
            cout<<res<<endl;
            continue;
        }else {
            ll z = y-x;
            x+=z;
        }
        x+=abs(D-C)*q;
        x+=abs(B-D)*p;
        res = min(res,x);
        cout<<res;
    }
    return 0;
}
