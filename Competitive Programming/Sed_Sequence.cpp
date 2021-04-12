#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) begin(x), end(x)

#define sz(x) (int)(x).size()

#define f first
#define s second

#define mp make_pair

#define ll long long
#define ld long double

int main() {
    ll T,x,n,k;
    cin>>T;
    while(T--) {
        cin>>n>>k;
        vector<ll> v;
        ll sum = 0;
        for(int i=0;i<n;i++) {
            cin>>x;
            sum+=x;
        }
        if(sum%k==0) {
            cout<<0<<endl;
        }else {
            cout<<1<<endl;
        }
    }
    return 0;
}


