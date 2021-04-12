#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

int main() {
    string s;
    cin>>s;
    vector<ll> v;
    for(ll i=0;i<s.length();i++) {
        if(s[i]!='+') {
            v.push_back(s[i]-'0');
        }
    }
    sort(v.begin(),v.end());
    cout<<v[0];
    for(ll i=1;i<v.size();i++) {
        cout<<"+"<<v[i];
    }
    return 0;
}



