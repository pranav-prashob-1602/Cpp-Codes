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
    string s;
    cin>>s;
    if(s.length()<26) {
        cout<<-1;
        return 0;
    }
    string r="";
    ll alp[26] = {0},cnt=0,c=0;
    for(ll j=0;j<26;j++) {
        if(s[j]=='?') {
            cnt++;
        }else {
            alp[s[j]-'A']++;
        }
    }
    for(ll k=0;k<26;k++) {
        if(alp[k]==1) {
            c++;
        }else {
            r+=('A'+k);
        }
    }
    //cout<<r<<endl;
    if(cnt+c==26 && cnt==r.length()) {
        for(ll k=0;k<26;k++) {
            if(s[k]=='?') {
                s[k] = r[cnt-1];
                cnt--;
            }
        }
        for(ll k=26;k<s.length();k++) {
            if(s[k]=='?') {
                s[k] = 'A';
            }
        }
        cout<<s;
        return 0;
    }
    bool resf = false;
    for(ll i=0;i<s.length()-25;i++) {
        c=0;
        r = "";
        //cout<<"123"<<endl;
        bool flag = false;
        if(i!=0) {
            if(s[i-1]=='?') {
                cnt--;
            }else {
                alp[s[i-1]-'A']--;
            }
            if(s[i+25]=='?') {
                cnt++;
            }else {
                alp[s[i+25]-'A']++;
            }
        }
        for(ll k=0;k<26;k++) {
            if(alp[k]==1) {
                c++;
            }else {
                r+=('A'+k);
            }
        }
        //cout<<r<<endl;
        if(cnt+c==26 && cnt==r.length()) {
            flag = true;
            resf = true;
        }else {
            continue;
        }
        if(flag) {
            for(ll k=0;k<i;k++) {
                if(s[k]=='?') {
                    s[k] = 'A';
                }
            }
            for(ll k=i;k<i+26;k++) {
                if(s[k]=='?') {
                    s[k] = r[cnt-1];
                    cnt--;
                }
            }
            for(ll k=i+26;k<s.length();k++) {
                if(s[k]=='?') {
                    s[k] = 'A';
                }
            }
            break;
        }
    }
    if(!resf) {
        cout<<-1;
    }else {
        cout<<s;
    }
    return  0;
}
