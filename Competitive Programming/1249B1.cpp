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

ll dfs(ll p[],ll x,ll z) {
    if(p[x]==z) {
        return 1;
    }
    return 1+dfs(p,p[x],z);
}

int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //Sieve(1000000);
    ll T,n,x;
    cin>>T;
    while(T--) {
        cin>>n;
        ll p[n+1];
        vector<ll> v;
        for(ll i=1;i<=n;i++) {
            cin>>x;
            v.pb(x);
            p[i] = x;
        }
        for(ll i=0;i<n;i++) {
            if(v[i]==i+1) {
                cout<<1<<" ";
                continue;
            }
            cout<<dfs(p,v[i],i+1)+1<<" ";
        }
        cout<<endl;
    }
    return 0;
}

