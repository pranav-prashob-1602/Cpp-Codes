#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

ll fact(ll n) {
    if(n<=1) {
        return 1;
    }
    return n*fact(n-1);
}

ll permute(vector<ll> v) {
    ll res = 1;
    for(auto& val : v) {
        res*=fact(val);
    }
    return res;
}

ll str_permute(string &s) {
    ll i;
    for(i=s.length()-1;i>0;i--) {
        if(s[i]>s[i-1]) {
            break;
        }
    }
    ll m = i;
    ll j,x=s[i-1];
    for(j=i+1;j<s.length();j++) {
        if((s[j]<s[m]) && s[j]>x) {
            m = j;
        }
    }
    swap(s[i-1],s[m]);
    sort(s.begin()+i,s.end());
    cout<<s<<endl;
}

int main() {
    string s;
    cin>>s;
    vector<ll> v(26,0);
    for(ll i=0;i<s.length();i++) {
        v[s[i]-'a']++;
    }
    sort(s.begin(),s.end());
    ll x = permute(v);
    ll res = fact(s.length())/x;
    cout<<res<<endl;
    cout<<s<<endl;
    for(ll i=0;i<res-1;i++) {
        str_permute(s);
    }
    return 0;
}
