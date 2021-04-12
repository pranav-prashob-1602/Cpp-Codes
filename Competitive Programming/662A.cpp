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
    string s;
    ll n;
    cin>>n;
    n-=1;
    for(ll i=1;i<=n;i++) {
        n-=i;
    }
    cout<<n+1<<endl;
    return 0;
}



