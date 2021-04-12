#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) begin(x), end(x)

#define sz(x) (int)(x).size()

#define ff first
#define ss second

#define mp make_pair

#define ll long long
#define ld long double

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin>>n;
    ll fib[n+1];
    for(ll i=0;i<=n;i++) {
        if(i<2) {
            fib[i]=1;
            continue;
        }
        fib[i]=fib[i-1]+fib[i-2];
    }
    cout<<fib[n];
    return 0;
}



