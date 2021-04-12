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
    ll a,b,c,m,x;
    string s;
    cin>>a>>b>>c;
    cin>>m;
    vector<pair<ll,string>> v;
    while(m--) {
        cin>>x>>s;
        v.pb(mp(x,s));
    }
    sort(all(v));
    ll cnt=0,res=0;
    for(ll i=0;i<v.size();i++) {
        if(a>0 && v[i].ss=="USB") {
            cnt++;
            a--;
            res+=v[i].ff;
        }else if(b>0 && v[i].ss=="PS/2") {
            cnt++;
            b--;
            res+=v[i].ff;
        }else if(c>0) {
            cnt++;
            c--;
            res+=v[i].ff;
        }
    }
    cout<<cnt<<" "<<res;
    return 0;
}
