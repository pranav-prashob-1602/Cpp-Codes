#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define mod 1000000007

ll twoPower(int x) {
    ll res = 1;
    ll y = 2;
    while(x>0) {
        if(x&1) {
            res = res*y % mod;
        }
        x=x>>1;
        y = y*y % mod;
    }
    return res;
}

int main() {
    ll n;
    cin>>n;
    cout<<twoPower(n);
    return 0;
}




