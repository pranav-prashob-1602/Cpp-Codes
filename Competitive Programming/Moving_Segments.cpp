#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) begin(x), end(x)

#define sz(x) (int)(x).size()

#define f first
#define s second

#define mp make_pair

#define ll long long
#define ld long double

int main() {
    ll n,T,x,l,r,v;
    string s;
    cin>>T;
    while(T--) {
        cin>>n;
        vector<pair<ll,pair<ll,ll>>> vct;
        set<pair<ll,pair<ll,ll>>> s;
        while(n--) {
            cin>>l>>r>>v;
            vct.pb(mp(l,mp(r,v)));
            s.insert(mp(l,mp(r,v)));
        }
        if(vct.size() == s.size()) {
            cout<<"YES"<<endl;
        }else {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}


