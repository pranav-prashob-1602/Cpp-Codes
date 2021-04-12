#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

int main() {
    ll T,x1,x2,y1,y2;
    cin>>T;
    while(T--) {
        cin>>x1>>y1>>x2>>y2;
        ll x = x1-x2;
        ll y = y1-y2;
        cout<<max(x,x2-1)+max(y,y2-1)<<endl;
    }
    return 0;
}


