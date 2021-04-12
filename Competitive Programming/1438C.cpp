#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

int main() {
    ll T,n,m;
    cin>>T;
    while(T--) {
        cin>>n>>m;
        ll a[n][m];
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                cin>>a[i][j];
            }
        }
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if((a[i][j] == a[i+1][j] && i+1<n) || (a[i][j] == a[i-1][j] && i-1>=0) || (a[i][j] == a[i][j+1] && j+1<m) || (a[i][j] == a[i][j-1] && j-1>=0)) {
                    a[i][j]+=1;
                }
                cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
