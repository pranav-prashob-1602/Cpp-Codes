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
    ld x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    vector<pair<ld,ld>> s;
    s.pb(mp(x1,y1));
    s.pb(mp(x2,y2));
    sort(all(s));
    //cout<<s[0].ff<<" "<<s[1].ff;
    ld x = (ld)abs(s[1].ff-s[0].ff);
    if(s[0].ff<0 && s[1].ff>=0) {
        ld a = (ld)abs(s[0].ff);
        x = (ld)a+s[1].ff;
    }
    ld z  = (ld) (s[1].ss*x/(ld)(s[0].ss+s[1].ss));
    ll p = (int)abs(s[0].ff+x-z);
    ll w = log10(p);
    w++;
    ld res = (ld)s[0].ff+x-z;
    cout<<setprecision(10+w)<<res;
    return 0;
}



