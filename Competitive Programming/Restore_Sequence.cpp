#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

vector<ll> res;

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
      res.push_back(p);
    }
  }
}


int main() {
    ll T,N,x;
    cin>>T;
    Sieve(5000000);
    while(T--) {
        cin>>N;
        for(int i = 0;i<N;i++) {
            cin>>x;
            cout<<res[x-1]<<" ";
        }
        cout<<endl;
    }
    return 0;
}


