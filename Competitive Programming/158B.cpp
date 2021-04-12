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
    ll T,n,x;
    cin>>n;
    vector<ll> m(5,0);
    for(ll i=0;i<n;i++) {
        cin>>x;
        m[x]++;
    }
    ll cnt=0;
    for(ll i=4;i>=1;i--) {
        if(i==4) {
            cnt+=m[i];
            m[i]=0;
        }else if(i==3) {
            if(m[i]<=m[4-i]) {
                m[4-i]-=m[i];
                cnt+=m[i];
            }else {
                cnt+=m[i];
                m[4-i]=0;
            }
            m[i]=0;
        }else if(i==2) {
            if(m[i]%2==0) {
                cnt+=m[i]/2;
                m[i]=0;
            }else {
                cnt+=m[i]/2;
                x = m[i]/2;
                m[i]-=(x)*2;
                if(m[i]*2<=m[i-1]) {
                    m[i-1]-=m[i]*2;
                    cnt+=m[i];
                    m[i]=0;
                }else {
                    cnt+=m[i];
                    m[i-1]=0;
                }
            }
        }else {
            cnt+=(m[i]+3)/4;
        }
    }
    cout<<cnt;
    return 0;
}
