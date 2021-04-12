#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

int main() {
    ll T,j;
    string s;
    cin>>T;
    while(T--) {
        cin>>s;
        vector<ll> v;
        for(int i=0;i<s.length();i++) {
            if(s[i]=='1') {
                j=i;
                while(s[j]=='1') {
                    j++;
                }
                v.push_back(j-i);
                i=j;
            }
        }
        sort(v.begin(),v.end(),greater<int>());
        ll res = 0;
        for(int i=0;i<v.size();i+=2) {
            res+=v[i];
        }
        cout<<res<<endl;
    }
    return 0;
}



