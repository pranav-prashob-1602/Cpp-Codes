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
    ll T,n,k,l,r;
    cin>>T;
    while(T--) {
        cin>>n>>k;
        ll a[n] = {0};
        while(k--) {
            cin>>l>>r;
            ll m =1;
            for(int i=l-1;i<=r-1;i++) {
                a[i]+=m;
                m++;
            }
        }
        for(int i=0;i<n;i++) {
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}


