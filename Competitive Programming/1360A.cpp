#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

int main() {
    ll T,n,m,x,p,q;
    cin>>T;
    while(T--) {
        cin>>n>>m;
        ll area = 2*n*m;
        x = sqrt(area);
        if(x*x<area) {
            x++;
        }
        p = max(n,m);
        q = min(n,m);
        if(p>x) {
            x=p;
        }
        if(2*q>x) {
            x = 2*q;
        }
        cout<<x*x<<endl;
    }
    return 0;
}


