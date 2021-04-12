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
    ll T,n,m,x;
    cin>>T;
    while(T--) {
        cin>>n>>m;
        ll a[n][m];
        for(ll i=0;i<n;i++) {
            for(ll j=0;j<m;j++) {
                cin>>a[i][j];
            }
        }
        ll r=0,c=0,i,j;
        for(i=0;i<n;i++) {
            for(j=0;j<m;j++) {
                if(a[i][j]==1) {
                    break;
                }
            }
            if(j==m)
                r++;
        }
        for(i=0;i<m;i++) {
            for(j=0;j<n;j++) {
                if(a[j][i]==1) {
                    break;
                }
            }
            if(j==n)
                c++;
        }
        ll cnt = min(r,c);
        if(cnt%2) {
            cout<<"Ashish"<<endl;
        }else {
            cout<<"Vivek"<<endl;
        }
    }
    return 0;
}

