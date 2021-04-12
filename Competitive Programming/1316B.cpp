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
        string s;
        cin>>n>>s;
        string pr,sf;
        string res = s;
        ll ind = 1;
        for(ll i=2;i<=n;i++) {
            pr = s.substr(0,i-1);
            sf = s.substr(i-1,n);
            if(n%2==i%2) {
                reverse(all(pr));
            }
            sf+=pr;
            if(sf<res) {
                res = sf;
                ind = i;
            }
        }
        cout<<res<<endl;
        cout<<ind<<endl;
    }
    return 0;
}


