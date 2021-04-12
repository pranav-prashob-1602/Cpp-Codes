#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define ld long double

int main()
{
  ll t,res;
  cin>>t;
  while(t--)
  {
    string s;
    cin>>s;
    ll u=count(s.begin(),s.end(), 'U');
    ll r=count(s.begin(),s.end(), 'R');
    ll l=count(s.begin(),s.end(), 'L');
    ll d=count(s.begin(),s.end(), 'D');
    ll x=0,y=0;
    for(auto c:s)
    {
      if(c=='L') x--;
      else if(c=='R') x++;
      else if(c=='D') y--;
      else if(c=='U') y++;
    }
    if(x!=0 && y!=0) {
        cout<<0<<" "<<0<<endl;
    } else if(x==0) {
        if(y>0) {
            res = u-d+1;
        }else {
            res = d-u;
        }
        cout<<r<<" "<<res<<endl;
    }else if(y==0) {
        if(x>0) {
            res = r-l+1;
        }else {
            res = r-l;
        }
        cout<<res<<" "<<u<<endl;
    }
  }
  return 0;
}
