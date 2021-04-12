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
#define lli long long int

#define mod 1000000007

ll powmod(ll a,  ll b){
    if(b==0){
        return 1 ;
    }
    ll x = powmod(a,b/2);
    x = (x*x)%mod ;
    if(b%2){
        x = (a*x)%mod ;
    }
    return x;
}

set<ll> prm;

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
  if(!prm.empty()) {
    prm.clear();
  }
  for(ll p=2;p<=n;p++)
  {
    if(prime[p])
    {
      prm.insert(p);
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
    ll T,n,x,cnt,temp;
    cin>>T;
    while(T--) {
        cin>>n;
        vector<ll> v;
        cnt=0;
        for(ll i=0;i<n;i++) {
            cin>>x;
            v.pb(x);
        }
        map<ll,ll> m;
        vector<ll> xr(n,0);
        xr[0] = v[0];
        for(ll i=1;i<n;i++) {
            xr[i] = xr[i-1]^v[i];
            //cout<<xr[i]<<" ";
        }
        //cout<<endl;
        for(ll i=0;i<n;i++) {
            cnt+=m[xr[i]%2];
            if(xr[i]%2==0) {
                cnt++;
            }
            m[xr[i]%2]++;
        }
        cout<<cnt<<endl;
    }
    return  0;
}
