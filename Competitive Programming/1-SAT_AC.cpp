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
    ll T;
    string s;
    cin>>T;
    map<string,ll> m;
    vector<string> v;
    while(T--) {
        cin>>s;
        v.pb(s);
        m[s]++;
    }
    for(ll i=0;i<v.size();i++) {
        if(v[i][0]=='!') {
            string s1 = v[i];
            s1.erase(s1.begin()+0);
            if(m[s1]>0) {
                cout<<s1;
                return 0;
            }
        }
    }
    cout<<"satisfiable";
    return 0;
}




