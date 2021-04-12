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

int p[2000];

int parent(int x) {
    if(p[x]==x) {
        return x;
    }
    return p[x] = parent(p[x]);
}

int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //Sieve(1000000);
    ll n,x;
    vector<ll> v;
    cin>>n;
    for(ll i=0;i<n;i++) {
        cin>>x;
        v.pb(x);
    }
    sort(all(v),greater<int> ());
    ll i=0,j=1,cnt=0;
    while(i!=n && j!=n) {
        if(v[j]==-1) {
            j++;
        }
        if(v[i]==-1) {
            i++;
        }
        if(v[j]*2<=v[i]) {
            v[j] = -1;
            cnt++;
            j++;
            i++;
        }else {
            j++;
        }
    }
    cout<<n-cnt;
    return 0;
}

