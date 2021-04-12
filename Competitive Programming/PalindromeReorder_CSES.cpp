#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

int main() {
    ll cnt = 0;
    string s;
    map<char,ll> m;
    cin>>s;
    char ch;
    ll z;
    for(ll i=0;i<s.length();i++) {
        m[s[i]]++;
    }
    for(auto& it : m) {
        if(it.second%2) {
            ch = it.first;
            z = it.second;
            cnt++;
        }
    }
    vector<char> v;
    if(s.length()%2) {
        if(cnt!=1) {
            cout<<"NO SOLUTION"<<endl;
            return 0;
        }
    }else {
        if(cnt>0) {
            cout<<"NO SOLUTION"<<endl;
            return 0;
        }
    }
    for(auto& it : m) {
        if(it.second%2==0) {
            for(int i=0;i<it.second/2;i++) {
                v.push_back(it.first);
            }
        }
    }
    for(auto it=v.begin();it!=v.end();it++) {
        cout<<*it;
    }
    if(cnt==1) {
        for(ll i=0;i<z;i++) {
            cout<<ch;
        }
    }
    for(auto it=v.rbegin();it!=v.rend();it++) {
        cout<<*it;
    }
    return 0;
}


