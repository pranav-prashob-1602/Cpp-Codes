#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

int main() {
    ll N;
    cin>>N;
    for(ll i=1;i<=N;i++) {
        ll x = pow(i,2);
        ll z = x*(x-1)/2;
        z-=4*(i-1)*(i-2);
        cout<<z<<endl;
    }
    return 0;
}


