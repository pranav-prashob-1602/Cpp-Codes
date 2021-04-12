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
    string s;
    cin>>s;
    vector<ll> v(10,0);
    for(auto& ch : s) {
        v[ch-'0']++;
    }
    if(s.size()==1) {
        if(s=="8") {
            cout<<"Yes";
        }else {
            cout<<"No";
        }
        return 0;
    }else if(s.size()==2) {
        if((10*(s[1]-'0')+(s[0]-'0'))%8==0 ||  (10*(s[0]-'0')+(s[1]-'0'))%8==0) {
            cout<<"Yes";
        }else {
            cout<<"No";
        }
        return 0;
    }else {
        for(ll i=0;i<=9;i++) {
            if(v[i]==0) {
                continue;
            }
            v[i]--;
            for(ll j=0;j<=9;j++) {
                if(v[j]==0) {
                    continue;
                }
                v[j]--;
                for(ll k=0;k<=9;k++) {
                    if(v[k]==0) {
                        continue;
                    }
                    if((100*i+10*j+k)%8==0) {
                        cout<<"Yes";
                        return 0;
                    }
                }
                v[j]++;
            }
            v[i]++;
        }
    }
    cout<<"No";
    return 0;
}
