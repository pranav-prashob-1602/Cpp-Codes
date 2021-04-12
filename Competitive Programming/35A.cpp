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
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n,a,b;
    cin>>n;
    for(ll i=0;i<3;i++) {
        cin>>a>>b;
        if(a==n) {
            n=b;
        }else if(b==n) {
            n=a;
        }
    }
    cout<<n;
    return 0;
}


