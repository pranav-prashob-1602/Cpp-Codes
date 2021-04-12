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
    ll T,n;
    cin>>T>>n;
    string s,s1;
    vector<string> v;
    for(int i=0;i<T;i++) {
        cin>>s;
        v.pb(s);
    }
    string mid ="";
    vector<string> l,r;
    vector<string> dup;
    for(int i=0;i<T;i++) {
        string t = v[i];
        reverse(t.begin(),t.end());
        if(v[i]==t) {
            mid = t;
        }else if(find(v.begin(),v.end(),t)!=v.end() && find(dup.begin(),dup.end(),t)==dup.end()) {
            l.pb(v[i]);
            r.pb(t);
            dup.pb(t);
            dup.pb(v[i]);
        }
    }
    if(mid.length()==0 && l.size()==0) {
        cout<<0;
    }else {
        if(l.size()==0) {
            cout<<mid.length()<<endl;
            cout<<mid;
        }else {
            s1= "";
            for(auto& val : l) {
                s1+=val;
            }
            s = s1;
            reverse(s1.begin(),s1.end());
            if(mid.length()!=0) {
                s+=mid;
            }
            s+=s1;
            cout<<s.length()<<endl;
            cout<<s;
        }
    }
    return 0;
}


