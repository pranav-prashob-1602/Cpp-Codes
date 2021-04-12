#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main()
{
    ll T,x,y,n,m,i,d,res;
    T=1;
    while(T--) {
        cin>>x>>n>>y>>m>>d;
        res = 0;
        for(i=1;i<=1000;i++) {
            if(x<=i) {
                res+=n;
            }
            if(y<=i) {
                res+=m;
            }
            if(res>=d) {
                break;
            }
        }
        cout<<i<<endl;
    }
    return 0;
}
