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
        vector<ll> v1,v2;
        for(int i=0;i<n;i++) {
            cin>>x;
            if(x%2) {
                v1.pb(i+1);
            }else {
                v2.pb(i+1);
            }
        }
        if(v2.size()!=0) {
            cout<<1<<endl;
            cout<<v2[0]<<endl;
        }else {
            if(v1.size()<2) {
                cout<<-1<<endl;
            }else {
                cout<<2<<endl;
                cout<<v1[0]<<" "<<v1[1]<<endl;
            }
        }
    }
    return 0;
}


