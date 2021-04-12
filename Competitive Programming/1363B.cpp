#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

int main() {
    ll T;
    string s;
    cin>>T;
    while(T--) {
        cin>>s;
        ll a = count(s.begin(),s.end(),'0');
        ll b = count(s.begin(),s.end(),'1');
        ll x=0,y=0,ans=min(a,b);
        for(int i=0;i<s.length();i++) {
                if(s[i]=='0') {
                    x++;
                }else {
                    y++;
                }
                ans=min(ans,min(x+b-y,y+a-x));
        }
        cout<<ans<<endl;
    }
    return 0;
}


