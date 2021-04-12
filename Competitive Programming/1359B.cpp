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
    ll T,n,m,a,b,res;
    cin>>T;
    while(T--) {
        cin>>n>>m>>a>>b;
        char fl[n][m];
        ll one,two;
        one=two=0;
        for(ll i=0;i<n;i++) {
            for(ll j=0;j<m;j++) {
                cin>>fl[i][j];
                if(fl[i][j]=='.') {
                    one++;
                }
            }
        }
        for(ll i=0;i<n;i++) {
            for(ll j=0;j<m-1;j++) {
                if(fl[i][j]=='.' && fl[i][j+1]=='.') {
                    j++;
                    two++;
                }
            }
        }
        res = one*a;
        for(ll i=1;i<=two;i++) {
            ll z = i*b + (one-i*2)*a;
            res = min(res,z);
        }
        cout<<res<<endl;
    }
    return 0;
}



