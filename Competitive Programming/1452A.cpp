#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

int main() {
    ll T,x,y;
    cin>>T;
    while(T--) {
        cin>>x>>y;
        ll p = x+y;
        ll q = max(abs(x-y)-1,(ll)0);
        cout<<p+q<<endl;
    }
    return 0;
}


