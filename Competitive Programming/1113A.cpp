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
    ll n,c;
    cin>>n>>c;
    if(n<c) {
        cout<<n-1;
        return 0;
    }
    ll res = c-1;
    for(ll i=1;i<=n-c;i++) {
        res+=i;
    }
    cout<<res;
    return 0;
}



