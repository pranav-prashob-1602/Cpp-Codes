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
    ll n,x,z;
    cin>>n;
    while(n--) {
        cin>>x;
        z = x^2;
        if(x==2) {
            z=1;
        }
        cout<<z<<" ";
    }
    return 0;
}



