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
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll T,n,x,k;
    cin>>T;
    while(T--) {
        cin>>n>>k;
        vector<ll> v;
        ll mn=0,mx=0,sum=0;
        bool flag = true;
        for(int i=0;i<n;i++) {
            cin>>x;
            v.pb(x);
            sum+=x;
            mx+=(x+k-1)/k;
        }
        mn = (sum+k-1)/k;
        cout<<mn<<" "<<mx<<endl;
    }
    return 0;
}


