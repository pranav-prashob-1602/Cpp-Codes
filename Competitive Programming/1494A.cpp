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
    ll n,a,b,c;
    string s;
    cin>>n;
    while(n--) {
        a=0,b=0,c=0;
        cin>>s;
        for(ll i=0;i<len(s);i++) {
            if(s[i]=='A') {
                a++;
            }else if(s[i]=='B') {
                b++;
            }else {
                c++;
            }
        }
        bool flag=(s[0]==s[len(s)-1]);
        string x="",y="";
        if(flag) {
            cout<<"NO"<<endll;
        }else {
            if(s[0]=='A') {
                if(s[len(s)-1]=='B') {
                    for(ll i=0;i<len(s);i++) {
                        if(s[i]=='A') {
                            x+='(';
                            y+='(';
                        }else if(s[i]=='B') {
                            x+=')';
                            y+=')';
                        }else {
                            x+='(';
                            y+=')';
                        }
                    }
                }else {
                    for(ll i=0;i<len(s);i++) {
                        if(s[i]=='A') {
                            x+='(';
                            y+='(';
                        }else if(s[i]=='C') {
                            x+=')';
                            y+=')';
                        }else {
                            x+='(';
                            y+=')';
                        }
                    }
                }
            }else if(s[0]=='B') {
                if(s[len(s)-1]=='A') {
                    for(ll i=0;i<len(s);i++) {
                        if(s[i]=='B') {
                            x+='(';
                            y+='(';
                        }else if(s[i]=='A') {
                            x+=')';
                            y+=')';
                        }else {
                            x+='(';
                            y+=')';
                        }
                    }
                }else {
                    for(ll i=0;i<len(s);i++) {
                        if(s[i]=='B') {
                            x+='(';
                            y+='(';
                        }else if(s[i]=='C') {
                            x+=')';
                            y+=')';
                        }else {
                            x+='(';
                            y+=')';
                        }
                    }
                }
            }else {
                if(s[len(s)-1]=='B') {
                    for(ll i=0;i<len(s);i++) {
                        if(s[i]=='C') {
                            x+='(';
                            y+='(';
                        }else if(s[i]=='B') {
                            x+=')';
                            y+=')';
                        }else {
                            x+='(';
                            y+=')';
                        }
                    }
                }else {
                    for(ll i=0;i<len(s);i++) {
                        if(s[i]=='C') {
                            x+='(';
                            y+='(';
                        }else if(s[i]=='A') {
                            x+=')';
                            y+=')';
                        }else {
                            x+='(';
                            y+=')';
                        }
                    }
                }
            }
            stack<char> st1,st2;
            for(auto& val : x) {
                if(val=='(') {
                    st1.push(val);
                }else {
                    if(st1.empty()) {
                        st1.push(val);
                        break;
                    }else {
                        if(st1.top()!='(') {
                            st1.push(val);
                            break;
                        }else {
                            st1.pop();
                        }
                    }
                }
            }
            for(auto& val : y) {
                    if(val=='(') {
                        st2.push(val);
                    }else {
                        if(st2.empty()) {
                            st2.push(val);
                            break;
                        }else {
                            if(st2.top()!='(') {
                                st2.push(val);
                                break;
                            }else {
                                st2.pop();
                            }
                        }
                    }
                }
                if(st1.size()==0 || st2.size()==0) {
                    cout<<"YES"<<endll;
                }else {
                    cout<<"NO"<<endll;
                }
            }
    }
    return 0;
}
