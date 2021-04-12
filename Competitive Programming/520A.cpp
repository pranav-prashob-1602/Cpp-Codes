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
    ll n;
    string s;
    cin>>n>>s;
    if(n<26) {
        cout<<"NO"<<endl;
        return 0;
    }
    vector<ll> res(26,0);
    for(ll i=0;i<s.length();i++) {
        if(isupper(s[i])) {
            res[s[i]-'A']++;
        }else {
            res[s[i]-'a']++;
        }
    }
    bool flag = true;
    for(ll i=0;i<26;i++) {
        flag&=(res[i]>0);
    }
    if(flag) {
        cout<<"YES"<<endl;
    }else {
        cout<<"NO"<<endl;
    }
    return 0;
}
