#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

int main() {
    ll T;
    cin>>T;
    string s1,s2;
    while(T--) {
        cin>>s1>>s2;
        ll cnt = 0;
        ll odd = 0,even = 0;
        for(ll i=0;i<s1.length();i+=2) {
                if(s1[i]!=s2[i]) {
                    even++;
                }else {
                    if(even>0) {
                        cnt++;
                    }
                    even = 0;
                }
        }
        if(even!=0) {
            cnt++;
        }
        for(ll i=1;i<s1.length();i+=2) {
                if(s1[i]!=s2[i]) {
                    odd++;
                }else {
                    if(odd>0) {
                        cnt++;
                    }
                    odd = 0;
                }
        }
        if(odd!=0) {
            cnt++;
        }
        cout<<cnt<<endl;
    }
    return 0;
}


