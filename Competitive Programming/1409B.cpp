#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

int main() {
    ll T,a,b,x,y,n;
    cin>>T;
    while(T--) {
        cin>>a>>b>>x>>y>>n;
        if(a+b-x-y<=n) {
            cout<<x*y<<endl;
            continue;
        }
        ll m=n,a1=a,b1=b;
        ll dx=a1-x;
        ll dy=b1-y;
        if(dy>=m) {
            b1-=m;
            m=0;
        }else {
            b1-=dy;
            m-=dy;
        }
        a1-=min(dx,m);
        ll res = a1*b1;
        if(dx>=n) {
            a-=n;
            n=0;
        }else {
            a-=dx;
            n-=dx;
        }
        b-=min(dy,n);
        res = min(res,a*b);
        cout<<res<<endl;
    }
    return 0;
}



