//score 100
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
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll T,n;
    cin>>T;
    while(T--) {
        cin>>n;
        ll a[n][n];
        memset(a,0,sizeof(a));
        a[0][0]=1;
        for(ll i=0;i<n;i++) {
            for(ll j=0;j<i+1;j++) {
                if(j==0 || j==i) {
                    a[i][j] = 1;
                }else {
                    a[i][j] = a[i-1][j-1] + a[i-1][j];
                }
                cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
