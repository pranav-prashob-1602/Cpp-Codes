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
    ll n,T,x;
    string s;
    cin>>T;
    while(T--) {
        cin>>n;
        vector<pair<string,ll>> v;
        while(n--) {
            cin>>s;
            cin>>x;
            v.pb(mp(s,x));
        }
        sort(all(v));
        ll zero,one,res=0;
        for(ll i=0;i<v.size();i++) {
            zero = one = 0;
            v[i].s==0 ? ++zero : ++one;
            while(v[i].f==v[i+1].f) {
                v[i+1].s==0 ? ++zero : ++one;
                i++;
            }
            res +=max(zero,one);
        }
        cout<<res<<endl;
    }
    return 0;
}


