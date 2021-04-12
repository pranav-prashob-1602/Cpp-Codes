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
    ll T,n,x;
    cin>>T;
    while(T--) {
        cin>>n;
        vector<ll> v;
        ll cnt = 0;
        for(ll i=0;i<n;i++) {
            cin>>x;
            v.pb(x);
        }
        while(v[cnt]==1 && cnt<n) {
            cnt++;
        }
        string s = !(cnt==n ^ cnt%2) ? "First" : "Second";
        cout<<s<<endl;
    }
    return 0;
}



