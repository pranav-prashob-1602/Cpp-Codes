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

ll fact(ll n) {
    ll res = 1;
    for(ll i=2;i<=n;i++) {
        res*=i;
    }
    return res;
}

ld nCr(ll n,ll r) {
    return (ld)fact(n)/(ld)(fact(r)*fact(n-r));
}

int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //Sieve(1000000);
    string s1,s2;
    cin>>s1>>s2;
    ll q = count(all(s2),'?');
    ll p = count(all(s1),'+') - count(all(s2),'+');
    ld res = 0.0;
    if(!(q<p || p<0)) {
        res = (ld)nCr(q,p)/pow(2,q);
    }
    ll x = log10(res)+1;
    cout<<setprecision(x+12)<<res<<endl;
    return 0;
}
