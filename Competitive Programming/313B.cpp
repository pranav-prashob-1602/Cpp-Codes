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
    ll n,x,y;
    string s;
    cin>>s;
    cin>>n;
    vector<ll> v;
    v.pb(0);
    for(ll i=1;i<s.length();i++) {
        x  = s[i]==s[i-1] ? 1 : 0;
        v.pb(x);
    }
    ll sum=0;
    for(ll i=0;i<v.size();i++) {
        sum+=v[i];
        v[i] = sum;
    }
    while(n--) {
        cin>>x>>y;
        ll c = v[y-1]-v[x-1];
        cout<<c<<endl;
    }
    return 0;
}
