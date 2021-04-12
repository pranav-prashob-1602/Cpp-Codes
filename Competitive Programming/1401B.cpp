#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

/*
3
2 3 2
3 3 1
4 0 1
2 3 0
0 0 1
0 0 1
*/

int main() {
    ll T,x1,x2,x3,y1,y2,y3;
    cin>>T;
    while(T--) {
        cin>>x1>>x2>>x3>>y1>>y2>>y3;
        ll r = min(x3,y2);
        ll res = 2*r - 2*max(0LL,y3-x3-x1+r);
        cout<<res<<endl;
    }
    return 0;
}



