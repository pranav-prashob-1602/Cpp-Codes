#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define ld long double
#define mod 1000000007

vector<ll> x,y;

bool chk(ll a,ll b)
{
  for(ll i=0;i<x.size();i++)
  {
    if(x[i]<=b and y[i]>=a) return true;
  }
  return false;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ll t;
  cin>>t;
  while(t--)
  {
  	ll n,m,p,q;
    cin>>n>>m>>p>>q;
    ll a[m],b[m],c[m],d[m];
    for(ll i=0;i<m;i++)
    {
      cin>>a[i]>>b[i]>>c[i]>>d[i];
    }
    if(p==q)
    {
      cout<<0<<"\n";
      continue;
    }
    ll f[m],ans=-1,cnt=0;
    vector<ll> v,w;
    memset(f,0,sizeof(f));
    v.push_back(p);
    w.push_back(p);
    while((ans==-1) and (v.size()!=0))
    {
      x.clear();
      y.clear();
      x=v;
      y=w;
      vector<ll> h,g;
      for(ll i=0;i<m;i++)
      {
        if(f[i]==0 and chk(a[i],b[i]))
        {
          h.push_back(c[i]);
          g.push_back(d[i]);
          if(c[i]<=q and d[i]>=q) ans=cnt+1;
          f[i]=1;
        }
      }
      v=h;
      w=g;
      cnt++;
    }
    cout<<ans<<"\n";
  }
  return 0;
}
