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

lli sumx(lli n) {
    lli sum=0;
    while(n!=0) {
        sum+=n%10;
        n/=10;
    }
    return sum;
}

int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //Sieve(1000000);
    ll n,m,x;
    vector<ll> a,b;
    cin>>n>>m;
    //map<ll,ll> mp,mp2;
    for(ll i=0;i<n;i++) {
        cin>>x;
        a.pb(x);
        //mp[x]++;
    }
    for(ll i=0;i<m;i++) {
        cin>>x;
        b.pb(x);
        //mp2[x]++;
    }
    ll i=0,j=0,k,cnt=0,cnt1=0,res=0;
    /*for(auto& val : mp) {
        res+=val.ss*mp2[val.ff];
    }*/
    while(i<n && j<m) {
        cnt=0;
        x = a[i];
        while(x==a[i] && i<n) {
            cnt++;
            i++;
        }
        //cout<<'a'<<cnt<<endl;
        while(x>b[j] && j<m) {
            j++;
        }
        if(x<b[j]) {
            continue;
        }
        cnt1=0;
        while(x==b[j] && j<m) {
            j++;
            //cout<<'b'<<b[j]<<endl;
            cnt1++;
        }
        //cout<<'b'<<cnt1<<endl;
        res+=cnt1*cnt;
    }
    cout<<res<<endl;
    return  0;
}
