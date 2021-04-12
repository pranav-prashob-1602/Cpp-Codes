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
    ll T;
    cin>>T;
    while(T--) {
        string str;
        map<char,ll> m;
        cin>>str;
        for(int i=0;i<str.length();i++) {
            m[str[i]]++;
        }
        ll cnt=0,cnt_2=0;
        for(auto& x : m) {
           ll val = x.s;
           cnt+=val%2;
           cnt_2+=val/2;
        }
        ll res = 0;
        if(cnt>=cnt_2) {
            res+=cnt_2;
        }else {
            res+=cnt;
            cnt_2-=cnt;
            ll z = cnt_2/3;
            res+=z*2;
            ll y = cnt_2%3;
            if(y==2) {
                res+=1;
            }
        }
        cout<<res<<endl;
    }
    return 0;
}


