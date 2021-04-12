#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

int main() {
    ll T,n,p,x;
    string s;
    cin>>T;
    while(T--) {
        cin>>p;
        n=p;
        map<char,ll> m;
        while(p--) {
            cin>>s;
            for(ll i=0;i<s.length();i++) {
                m[s[i]]++;
            }
        }
        bool flag = true;
        for(auto& it : m) {
            x = it.second;
            //cout<<x<<" "<<x%n<<endl;
            flag&=(x%n==0);
        }
        if(flag) {
            cout<<"YES"<<endl;
        }else {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}



