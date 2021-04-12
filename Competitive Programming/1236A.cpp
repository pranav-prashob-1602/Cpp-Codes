#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

int main() {
    ll T,a,b,c,x;
    cin>>T;
    while(T--) {
        cin>>a>>b>>c;
        ll res = 0;
        c = c - c%2;
        x = c/2;
        if(b<x) {
            res+=b*3;
            b = 0;
        }else {
            res+=c+x;
            b-=x;
        }
        b = b - b%2;
        x = b/2;
        if(a<x) {
            res+=a*3;
            a=0;
        }else {
            res+=b+x;
            a-=x;
        }
        cout<<res<<endl;
    }
    return 0;
}


