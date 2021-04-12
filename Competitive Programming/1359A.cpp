#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

int main() {
    ll T,n,m,k;
    cin>>T;
    while(T--) {
        cin>>n>>m>>k;
        ll x = n/k;
        x = x>m ? m : x;
        ll res = abs(x - (m-x+k-2)/(k-1));
        cout<<res<<endl;
    }
    return 0;
}


