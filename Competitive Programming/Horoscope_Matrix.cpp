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
    ll T,x,n,k,y,z,m;
    cin>>T;
    while(T--) {
        cin>>n>>m;
        set<ll> s;
        vector<ll> v;
        ll a[n][m];
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                cin>>a[i][j];
            }
        }
        cin>>k;
        while(k--) {
            cin>>x>>y>>z;
            bool flag = true;
            if(x==y) {
                a[x-1][y-1] = z;
                for(int i=0;i<n;i++) {
                    flag&=(a[i][i]==a[0][0]);
                }
                if(flag) {
                    cout<<"Yes"<<endl;
                }else {
                    cout<<"No"<<endl;
                }
            }else {
                cout<<"Yes"<<endl;
            }
        }
    }
    return 0;
}


