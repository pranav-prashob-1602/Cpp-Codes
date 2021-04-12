#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

int main() {
    ll T,n,x;
    string s;
    T = 1;
    while(T--) {
        cin>>n>>s;
        vector<ll> v;
        for(int i=0;i<n;i++) {
            cin>>x;
            v.push_back(x);
        }
        ll i=0,res = 1;
        while(true) {
            if(s[i]=='>') {
                res += 1 * v[i];
            }else {
                res+=-1*v[i];
            }
            if(res<0 && res>=n) {
                cout<<"FINITE";
                break;
            }
            i++;
        }
    }
    return 0;
}



