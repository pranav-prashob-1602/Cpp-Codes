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
    ld T,x,y;
    vector<pair<ld,ld>> v;
    cin>>T;
    while(T--){
        cin>>x>>y;
        v.pb(mp(x,y));
    }
    ll cnt=0;
    for(ll i=0;i<v.size()-1;i++) {
        for(ll j=i+1;j<v.size();j++) {
            ld z = (ld) (v[j].ss - v[i].ss)/(v[j].ff-v[i].ff);
            if(z>=-1 && z<=1) {
                //cout<<v[j].ss<<" "<<v[i].ss<<endl;
                cnt++;
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
}



