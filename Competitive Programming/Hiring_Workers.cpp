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
    ll T,a,b;
    cin>>T;
    while(T--) {
        cin>>a>>b;
        vector<ll> v;
        for(ll i =1;i<=b;i++) {
            if(b%i==0) {
                v.push_back(i);
            }
        }
        if(v.size()==2) {
            cout<<b+(a-1)<<endl;
        }else {
            if(res.size()>0) {
                res.clear();
            }
            Sieve(b+1);
            ll cnt = 0;
            ll arr[2] = {0};
            for(ll i = 0;res[i]<b && i<res.size();i++) {
                if(b%res[i]==0) {
                    arr[cnt] = res[i];
                    cnt++;
                }
                if(cnt==2) {
                    break;
                }
            }
            if(cnt!=2) {
                cout<<arr[0]*(a-1)+b<<endl;
                continue;
            }
            cout<<arr[0]*(a-1)+arr[1]<<endl;
        }
    }
    return 0;
}


