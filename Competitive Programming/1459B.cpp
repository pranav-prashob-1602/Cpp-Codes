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

#define mod 1000000007

int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin>>n;
    vector<ll> v(n+2);
    v[0] = 1;
    v[1] = 4;
    v[2] = 4;
    if(n<3) {
        cout<<v[n]<<endl;
        return 0;
    }
    if(n%2) {
        for(ll i=3;i<=n;i+=2) {
            v[i] = v[i-2]+4*(i/2-1) + 8;
        }
    }else {
        for(ll i=4;i<=n;i+=2) {
            v[i] = v[i-4]+i*2;
        }
    }
    cout<<v[n]<<endl;
    return 0;
}


