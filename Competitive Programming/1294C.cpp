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
    ll T,n;
    cin>>T;
    while(T--) {
        cin>>n;
        set<ll> s;
        for(ll i=2;i*i<=n;i++) {
            if(n%i==0) {
                s.insert(i);
                n/=i;
                break;
            }
        }
        for(ll i=2;i*i<=n;i++) {
            if(n%i==0 && s.count(i)==0) {
                n/=i;
                s.insert(i);
                break;
            }
        }
        if(s.size()<2 || s.count(n)!=0 || n==1) {
            cout<<"NO"<<endl;
        }else {
            cout<<"YES"<<endl;
            for(auto& val : s) {
                cout<<val<<" ";
            }
            cout<<n<<endl;
        }
    }
    return 0;
}
