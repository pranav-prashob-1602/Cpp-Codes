#include<bits/stdc++.h>

/*

shinchanCoder Here!!

*/

using namespace std;

#define pb push_back
#define all(x) begin(x), end(x)

#define sz(x) (int)(x).size()

#define ff first
#define ss second

#define mp make_pair

#define ll long long
#define ld long double

#define mod 1000000007

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n,m,x,p;
    ll b,s;
    b = INT_MAX;
    s = INT_MIN;
    cin>>n>>m>>x;
    while(n--) {
        cin>>p;
        b = min(b,p);
    }
    while(m--) {
        cin>>p;
        s = max(s,p);
    }
    ll q = x/b;
    ll res = max(x,x+(s-b)*q);
    cout<<res<<endl;
    return 0;
}

