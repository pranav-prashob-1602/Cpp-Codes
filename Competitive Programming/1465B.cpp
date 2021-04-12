#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) begin(x), end(x)

#define sz(x) (int)(x).size()

#define f first
#define s second

#define mp make_pair

#define ll long long
#define ld long double

int main() {
    ll T,n;
    string s;
    cin>>T;
    while(T--) {
        cin>>s;
        n = stoi(s);
        ll cnt = 0;
        ll res = n,y;
        for(int i=0;i<s.length();i++) {
            ll x = s[i]-'0';
            if(n%x!=0) {
                if(cnt==0) {
                    y = n/x;
                    res = (y+1)*x;
                }else {
                    y = n/x;
                    res = min(res,(y+1)*x);
                }
                cnt++;
            }
        }
        cout<<res<<endl;
    }
    return 0;
}


