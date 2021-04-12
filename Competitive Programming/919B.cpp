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

#define mod 1000000007

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n,ans=0;
    cin>>n;
    ll sum;
    while(n!=0) {
        ans++;
        ll k = ans;
        sum=0;
        while(k!=0) {
            sum+=k%10;
            k/=10;
        }
        if(sum==10) {
            n--;
        }
    }
    cout<<ans;
    return 0;
}



