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
    ll n,k;
    cin>>n>>k;
    ll z = log2(n);
    priority_queue<ll> p;
    ll m = pow(2,z);
    ll temp = n;
    while(m!=0 && temp!=0) {
        if(temp-m<0) {
            m/=2;
            continue;
        }
        p.push(m);
        temp-=m;
    }
    while(p.size()!=n) {
        if(p.size()>=k) {
            break;
        }
        z = p.top();
        if(z==1) {
            break;
        }
        p.pop();
        p.push(z/2);
        p.push(z/2);
    }
    if(p.size()!=k) {
        cout<<"NO"<<endl;
    }else {
        cout<<"YES"<<endl;
        while(!p.empty()) {
            cout<<p.top()<<" ";
            p.pop();
        }
    }
    return  0;
}
