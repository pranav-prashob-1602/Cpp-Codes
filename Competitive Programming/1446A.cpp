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
    ll T,n,w,x;
    cin>>T;
    while(T--) {
        cin>>n>>w;
        vector<pair<ll,ll>> v;
        for(int i=0;i<n;i++) {
            cin>>x;
            v.pb(mp(x,i+1));
        }
        sort(all(v));
        ll sum = 0;
        vector<ll> ind;
        for(int i=n-1;i>=0;i--) {
            if(sum+v[i].ff>w) {
                continue;
            }
            sum+=v[i].ff;
            ind.pb(v[i].ss);
        }
        if(sum<(w+1)/2) {
            cout<<-1<<endl;
            continue;
        }
        sort(all(ind));
        cout<<ind.size()<<endl;
        for(auto& val: ind) {
            cout<<val<<" ";
        }
        cout<<endl;
    }
    return 0;
}
