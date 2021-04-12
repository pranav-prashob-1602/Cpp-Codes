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

bool prime[1000000];

void Sieve(ll n)
{
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

set<ll> no;

void fun(ll i, ll n) {
    if(i==18) {
        if(n!=0) {
            no.insert(n);
        }
        return;
    }
    fun(i+1,n*10+9);
    fun(i+1,n*10);
}

int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    Sieve(1000000);
    ll ans[1000001]={0};
    for(ll i=4;i<=1000000;i++) {
        if(prime[i] && prime[i-2]) {
            ans[i] = ans[i-1]+1;
        }else {
            ans[i] = ans[i-1];
        }
    }
    ll T,n;
    cin>>T;
    while(T--) {
        cin>>n;
        cout<<ans[n]<<endl;
    }
    return  0;
}
