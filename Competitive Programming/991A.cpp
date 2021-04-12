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
    ll a,b,c,n;
    cin>>a>>b>>c>>n;
    if(a-c<0 || b-c<0 || a+b-c>=n) {
        cout<<-1;
    }else {
        cout<<n-(a+b-c);
    }
    return 0;
}


