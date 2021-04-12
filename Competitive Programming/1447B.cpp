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
        ll min_ele = INT_MAX;
        ll sum=0,neg =0;
        for(ll i=0;i<n;i++) {
            for(ll j=0;j<m;j++) {
                cin>>a[i][j];
                min_ele = min(min_ele,abs(a[i][j]));
                sum+=abs(a[i][j]);
                if(a[i][j]<0) {
                    neg+=1;
                }
            }
        }
        if(neg%2==0) {
            cout<<sum<<endl;
        } else {
            cout<<sum-2*min_ele<<endl;
        }
    }
    return 0;
}
/*
2
2 2
-1 1
1 1
3 4
0 -1 -2 -3
1 -2 -3 -4
-2 -3 -4 -5
*/
