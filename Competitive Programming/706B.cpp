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
    ll n,m,x,cnt=0,p;
    vector<ll> v;
    cin>>n;
    for(ll i=0;i<n;i++) {
        cin>>x;
        v.pb(x);
    }
    sort(all(v));
    cin>>m;
    while(m--) {
        cin>>p;
        cnt=upper_bound(all(v),p)-v.begin();
        cout<<cnt<<endl;
    }
    return 0;
}

/*
5
3 10 8 6 11
4
1
10
3
11
*/
