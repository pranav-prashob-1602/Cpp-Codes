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
    ll T;
    cin>>T;
    while(T--) {
        string s1,s2;
        cin>>s1>>s2;
        ll n= s1.length();
        ll m = s2.length();
        ll l = lcm(n,m);
        string a,b;
        if(n<m) {
            a = s1;
            b = s2;
        }else {
            a = s2;
            b = s1;
        }
        string res="";
        while(res.length()<l) {
            res+=a;
        }
        string r="";
        while(r.length()<l) {
            r+=b;
        }
        if(res!=r) {
            cout<<-1<<endl;
        }else {
            cout<<res<<endl;
        }
    }
    return 0;
}

