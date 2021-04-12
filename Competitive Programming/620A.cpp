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
    ll x1,x2,y1,y2;
    cin>>x1>>y1;
    cin>>x2>>y2;
    cout<<max(abs(x2-x1),abs(y2-y1));
    return 0;
}


