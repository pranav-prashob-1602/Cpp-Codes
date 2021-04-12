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
    ll n,T,x,y;
    cin>>n>>T;
    string s;
    cin>>s;
    while(T--) {
        string a;
        cin>>a;
        if(a=="substr") {
            cin>>x>>y;
            if(x>y) {
                swap(x,y);
            }
            string res = s.substr(x-1,y-x+1);
            cout<<res<<endl;
        }else if(a=="sort") {
            cin>>x>>y;
            if(x>y) {
                swap(x,y);
            }
            sort(s.begin()+x-1,s.begin()+y);
        }else if(a=="pop_back") {
            s.pop_back();
        }else if(a=="back") {
            cout<<s[s.length()-1]<<endl;
        }else if(a=="reverse") {
            cin>>x>>y;
            if(x>y) {
                swap(x,y);
            }
            reverse(s.begin()+x-1,s.begin()+y);
        }else if(a=="front") {
            cout<<s[0]<<endl;
        }else if(a=="print") {
            cin>>x;
            cout<<s[x-1]<<endl;
        }else if(a=="push_back") {
            char ch;
            cin>>ch;
            s+=ch;
        }
    }
    return  0;
}
