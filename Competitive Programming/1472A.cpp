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
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll T,x,y,n;
    cin>>T;
    while(T--) {
        cin>>x>>y>>n;
        if(n==1) {
            cout<<"YES"<<endl;
            continue;
        }
        ll cnt_x=0,cnt_y=0;
        ll k=2;
        while(x%2==0) {
            x/=2;
            cnt_x++;
        }
        while(y%2==0) {
            y/=2;
            cnt_y++;
        }
        if(pow(2,cnt_x+cnt_y)>=n) {
            cout<<"YES"<<endl;
        }else {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
