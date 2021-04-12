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
    ll a,b,n,m;
    bool flag = true;
    cin>>a>>b;
    n = min(a,b);
    m = max(a,b);
    ll cnt=0;
    if(n==m && n==1) {
        cout<<0;
        return 0;
    }
    while(n>0 && m>0) {
        if(flag) {
            m-=2;
            n++;
            if(m-2<1) {
                flag = !flag;
            }
        }else {
            n-=2;
            m++;
            if(n-2<1) {
                flag = !flag;
            }
        }
        cnt++;
    }
    cout<<cnt;
    return 0;
}
