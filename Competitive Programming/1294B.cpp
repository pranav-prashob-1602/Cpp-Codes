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
    ll T,n,x,y;
    cin>>T;
    while(T--){
        vector<pair<ll,ll>> v;
        cin>>n;
        for(ll i=0;i<n;i++) {
            cin>>x>>y;
            v.pb(mp(x,y));
        }
        sort(all(v));
        string s = "";
        x =0,y=0;
        ll i=0;
        /*for(int i=0;i<n;i++) {
            cout<<v[i].ff<<" "<<v[i].ss<<endl;
        }*/
        for(i=0;i<n;i++) {
            if(x>v[i].ff || y>v[i].ss) {
                break;
            }
            for(ll j=0;j<v[i].ff-x;j++) {
                s+='R';
            }
            for(ll j=0;j<v[i].ss-y;j++) {
                s+='U';
            }
            x = v[i].ff;
            y = v[i].ss;
        }
        if(i!=n) {
            cout<<"NO"<<endl;
        }else {
            cout<<"YES"<<endl;
            cout<<s<<endl;
        }
    }
    return 0;
}
