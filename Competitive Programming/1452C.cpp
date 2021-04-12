#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

int main() {
    ll T,x,y,cnt;
    string s;
    cin>>T;
    while(T--) {
        cnt = x = y =0;
        cin>>s;
        for(ll i =0;i<s.length();i++) {
            if(s[i]=='(') {
                    x++;
                    continue;
            }
            if(s[i]=='[') {
                y++;
                continue;
            }
            if(s[i]==')') {
                if(x>0) {
                    x--;
                    cnt++;
                }
                continue;
            }
            if(s[i]==']') {
                if(y>0) {
                    y--;
                    cnt++;
                }
                continue;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}


