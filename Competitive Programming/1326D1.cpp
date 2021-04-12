  #include<bits/stdc++.h>

/*

shinchanCoder Here!!

*/

using namespace std;

#define endll "\n"
#define pb push_back
#define all(x) begin(x), end(x)
#define allr(x) rbegin(x), rend(x)
#define forn(i,n) for(ll i=0;i<(n);i++)

#define sz(x) (int)(x).size()

#define ff first
#define ss second

#define mpr make_pair

#define len(x) x.length()

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

ll power(ll x, ll y) {
    ll res = 1;
    while (y > 0) {
        if (y & 1)
            res = res*x;
        y = y>>1;
        x = x*x;
    }
    return res;
}


vector<ll> prm;

void Sieve(ll n) {
  bool prime[n+1];
  memset(prime,true, sizeof(prime));
  for(ll p=2;p*p<=n;p++) {
    if(prime[p]==true) {
      for(ll i=p*p;i<=n;i+=p) {
        prime[i]=false;
      }
    }
  }
  if(!prm.empty()) {
    prm.clear();
  }
  for(ll p=2;p<=n;p++) {
    if(prime[p]) {
      prm.pb(p);
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
    ll T;
    cin>>T;
    while(T--) {
        string s;
        cin>>s;
        string pref="",suff="";
        ll i=0,j=len(s)-1;
        while(i<j) {
            if(s[i]==s[j]) {
                pref+=s[i];
                suff=s[j]+suff;
            }else {
                break;
            }
            i++;
            j--;
        }
        string r="",res="";
        for(ll k=i;k<j;k++) {
            r+=s[k];
            string x=r;
            reverse(all(r));
            if(x==r) {
                if(len(res)<len(r)) {
                    res=r;
                }
            }
            r=x;
        }
        r="";
        string res1="";
        for(ll k=j;k>=i;k--) {
            r+=s[k];
            string x=r;
            reverse(all(r));
            if(x==r) {
                if(len(res1)<len(r)) {
                    res1=r;
                }
            }
            r=x;
        }
        string result="";
        if(len(pref)==0 && len(suff)==0) {
            if(len(res1)>len(res)) {
                result=res1;
            }else {
                result=res;
            }
        }else {
            if(len(res1)>len(res)) {
                result=pref+res1+suff;
            }else {
                result=pref+res+suff;
            }
        }
        cout<<result<<endll;
    }
    return 0;
}



