#include<bits/stdc++.h>

/*

shinchanCoder Here!!

*/

using namespace std;

#define pb push_back
#define all(x) begin(x), end(x)
#define allr(x) rbegin(x), rend(x)

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

ll _lcm(ll x,ll y) {
    return x*y/__gcd(x,y);
}

ll _gcd(ll a,ll b) {
    if(!a) {
        return b%mod;
    }
    return _gcd((b%a)%mod,a%mod);
}

ll nCr(ll n,ll r) {
    return (ld)fact(n)/(ld)(fact(r)*fact(n-r));
}

bool twoPower(int n) {
    if(n==0) {
        return false;
    }
    return (ceil(log2(n)) == floor(log2(n)));
}

bool solve(vector<ll> v,ll sum,ll i,ll m) {
    if(sum%m==0 && sum!=0) {
        return true;
    }
    if(i<0) {
        return false;
    }
    return solve(v,sum+v[i],i-1,m) | solve(v,sum,i-1,m);
    return false;
}

int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //Sieve(1000000);
    ll n,m,x;
    cin>>n>>m;
    vector<ll> v;
    ll sum=0,cnt=0;
    for(ll i=0;i<n;i++) {
        cin>>x;
        v.pb(x);
        if(x==0) {
            cnt++;
        }
        sum+=x;
    }
    if(sum==0 || cnt>0) {
        cout<<"YES"<<endl;
        return 0;
    }
    if(solve(v,0,n-1,m)) {
        cout<<"YES"<<endl;
    }else {
        cout<<"NO"<<endl;
    }
    return  0;
}