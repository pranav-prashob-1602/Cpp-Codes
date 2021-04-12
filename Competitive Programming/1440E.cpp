#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main()
{
  ll n,q,w;
  cin>>n>>q;
  vector<ll> v;
  vector<ll>::iterator it;
  for(int i=1;i<=n;i++)
  {
    cin>>w;
    v.push_back(w);
  }
  while(q--)
  {
    ll t,x,y,cnt=0;
    cin>>t>>x>>y;
    if(t==1)
    {
        it=v.begin();
        fill(v.begin(),v.begin()+x-1,max(it++,y));
    }
    else if(t==2)
    {
      for(int i=x-1;i<n;i++)
      {
        if(y>=v[i])
        {
          y=y-v[i];
          cnt++;
        }
      }
      cout<<cnt<<endl;
    }
  }
  return 0;
}
