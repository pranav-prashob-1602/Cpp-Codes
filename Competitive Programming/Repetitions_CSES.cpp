#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

int main() {
    char s[1000000];
    cin>>s;
    char ch = s[0];
    ll cnt = 0,m=0;
    for(int i=0;i<strlen(s);i++) {
        if(s[i]==ch) {
            cnt++;
        }else {
            ch = s[i];
            m = max(cnt,m);
            cnt = 1;
        }
    }
    cout<<max(m,cnt);
    return 0;
}



