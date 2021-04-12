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
    ll n,k,x,sum=0;
    cin>>n>>k;
    vector<ll> v;
    for(ll i=0;i<n;i++) {
        cin>>x;
        if(i<k) {
            sum+=x;
        }
        v.pb(x);
    }
    vector<ll> res;
    res.pb(sum);
    for(ll i=1;i<=(n-k);i++) {
        sum-=v[i-1];
        sum+=v[i+k-1];
        res.pb(sum);
    }
    /*for(auto& val : res) {
        cout<<val<<" ";
    }*/
    ll ind = min_element(all(res))-res.begin();
    cout<<ind+1;
    return 0;
}
