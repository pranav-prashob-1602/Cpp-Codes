#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

int main() {
    ll T,n,m;
    cin>>T;
    while(T--) {
        cin>>n>>m;
        ll z = n*m;
        ll res = (z+1)/2;
        cout<<res<<endl;
    }
    return 0;
}


