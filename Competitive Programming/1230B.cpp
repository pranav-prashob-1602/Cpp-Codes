#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

int main() {
    ll T,n,k;
    T=1;
    string s;
    while(T--) {
        cin>>n>>k>>s;
        ll  cnt = 0;
        string res = "";
        for(int i=0;i<n;i++) {
            if(cnt<k) {
                if(i==0) {
                    if(s[i]!='1') {
                        cnt++;
                    }
                    res+=n==1 ? '0':'1';
                }else {
                    if(s[i]!='0') {
                        cnt++;
                    }
                    res+='0';
                }
            }else {
                res+=s[i];
            }
        }
        cout<<res<<endl;
    }
    return 0;
}


