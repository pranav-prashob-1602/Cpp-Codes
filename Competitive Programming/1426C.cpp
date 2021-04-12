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
        ll x = sqrt(n);
        ll res = x-1;
        res+=(n-x)/x;
        if((n-x)%x!=0) {
            res+=1;
        }
        cout<<res<<endl;
    }
    return 0;
}


