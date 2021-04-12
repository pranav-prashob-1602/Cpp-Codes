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
    ll n;
    cin>>n;
    ll cnt = 0;
    while(n!=0) {
        ll d = n;
        ll res = 0;
        while(d!=0) {
            res = max(res,d%10);
            d/=10;
        }
        n-=res;
        cnt++;
    }
    cout<<cnt;
    return 0;
}
