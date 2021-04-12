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
    ll T,n,k;
    cin>>T;
    while(T--) {
        string s,s1="",s2="";
        cin>>n>>s;
        s1+='1';
        s2+='1';
        for(ll i=1;i<s.length();i++) {
            if(s[i]=='0') {
                s1+='0';
                s2+='0';
            }else if(s[i]=='2') {
                if(s1>s2) {
                    s1+='0';
                    s2+='2';
                }else if(s1==s2) {
                    s1+='1';
                    s2+='1';
                }else {
                    s1+='2';
                    s2+='0';
                }
            }else {
                if(s1>s2) {
                    s1+='0';
                    s2+='1';
                }else {
                    s1+='1';
                    s2+='0';
                }
            }
        }
        cout<<s1<<endl;
        cout<<s2<<endl;
    }
    return  0;
}
