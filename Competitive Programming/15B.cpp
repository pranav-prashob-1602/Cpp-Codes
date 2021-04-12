#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

int main() {
    ll T,n,m,x1,x2,y1,y2;
    cin>>T;
    while(T--) {
        cin>>n>>m>>x1>>y1>>x2>>y2;
        ll a = abs(x1-x2);
        ll b = abs(y1-y2);
        ll res = n*m - 2*(n-a)*(m-b) + max((ll)0,n-2*a)*max((ll)0,m-2*b);
        cout<<res<<endl;
    }
    return 0;
}


