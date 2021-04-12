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

#define mod 1000000007

set<ll> res;

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
  if(!res.empty()) {
    res.clear();
  }
  for(ll p=2;p<=n;p++)
  {
    if(prime[p])
    {
      res.insert(p);
    }
  }
}

int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //Sieve(1000000);
    ll T,n,m,x,y;
    cin>>T;
    while(T--) {
        cin>>n>>m;
        string s;
        cin>>s;
        ll l = s.length();
        ll dp[l+1];
        dp[0] = 1;
        set<ll> st;
        st.insert(0);
        ll x = 0;
        for(ll i=0;i<s.length();i++) {
            if(s[i]=='-') {
                x--;
            }else {
                x++;
            }
            st.insert(x);
            dp[i+1] = st.size();
        }
        for(ll i=s.length();i>1;i--) {
            //dp[i]-=dp[i-1];
        }
        for(ll i=0;i<=s.length();i++) {
            //cout<<dp[i]<<" ";
        }
        ll t[l+1][l+1];
        for(ll i=0;i<=l;i++) {
            for(ll j=0;j<=l;j++) {
                if(i==0 || j==0) {
                    if(i==0) {
                        t[i][j] =dp[j];
                    }
                    if(j==0) {
                        t[i][j] = 0;
                    }
                    continue;
                }
                if(s[i-1]==s[j-1]) {
                    t[i][j] = max(t[i-1][j],t[i][j-1]);
                }else {
                    t[i][j] = 1+t[i-1][j-1];
                }
            }
        }
        while(m--) {
            cin>>x>>y;
            cout<<t[x][y]<<endl;
        }
    }
    return 0;
}

