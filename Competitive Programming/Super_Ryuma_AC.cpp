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
    ll r1,c1,r2,c2;
    cin>>r1>>c1>>r2>>c2;
    ll x = abs(r1-r2);
    ll y = abs(c1-c2);
    ll res = 0;
    if(x==0 && y==0) {
        res = 0;
    }else if(x==y || (x+y)<=3) {
        res = 1;
    }else if(x+y<=6 || abs(x-y)<=3 || (x+y)%2==0) {
        res = 2;
    }else {
        res = 3;
    }
    cout<<res;
    return 0;
}

