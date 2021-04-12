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
    ll cnt=1;
    ll k=4;
    for(int i=1;i<n;i++) {
        cnt+=k;
        k+=4;
    }
    cout<<cnt;
    return 0;
}


