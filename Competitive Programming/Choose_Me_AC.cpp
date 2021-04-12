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

bool cmp(pair<ll,ll> a,pair<ll,ll> b) {
    return (a.ff+a.ss)>(b.ff+b.ss);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll T,a,b;
    ll suma=0;
    cin>>T;
    vector<ll> c;
    while(T--){
        cin>>a>>b;
        c.pb(2*a+b);
        suma+=a;
    }
    sort(c.rbegin(),c.rend());
    ll cnt=0;
    for(auto& val : c) {
        suma-=val;
        cnt++;
        if(suma<0) {
            break;
        }
    }
    cout<<cnt;
    return 0;
}




