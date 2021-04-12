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
    ll n,res;
    cin>>n;
    if(n%2) {
        cout<<0;
    }else {
        res = 1<<(n/2);
        cout<<res;
    }
    return 0;
}



