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

int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //Sieve(1000000);
    ll n,mx=0,mxb=0;
    cin>>n;
    string s;
    cin>>s;
    ll cnt=0,len=0,j,k;
    bool flag = true;
    for(ll i=0;i<n;i++) {
        if(s[i]=='(') {
            mx = max(len,mx);
            len=0;
            cnt=0;
            j = i+1;
            k=i;
            while(s[j]=='_') {
                j++;
            }
            i=j;
            while(s[j]!=')') {
                if(s[j]=='_') {
                    while(s[j]=='_') {
                        j++;
                    }
                    cnt++;
                }else {
                    j++;
                }
            }
            i=j;
            while(s[j-1]=='_') {
                j--;
            }
            if(i!=j) {
                cnt--;
            }
            if(i-k>cnt+1) {
                cnt++;
            }
            //cout<<cnt<<endl;
            mxb+=max(cnt,0LL);
        }else {
            if(s[i]=='_' || s[i]=='(') {
                //cout<<len<<endl;
                mx = max(len,mx);
                len=0;
            }else {
                len++;
            }
        }
    }
    mx = max(mx,len);
    cout<<mx<<" "<<mxb;
    return  0;
}
