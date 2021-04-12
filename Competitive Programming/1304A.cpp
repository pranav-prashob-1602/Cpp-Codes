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
    ll x,y,n,m,T;
    cin>>T;
    while(T--){
        cin>>x>>y>>n>>m;
        ll res = (y-x)%(n+m) !=0 ? -1 : (y-x)/(n+m) ;
        cout<<res<<endl;
    }
    return 0;
}


