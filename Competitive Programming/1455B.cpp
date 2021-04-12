#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

int main() {
    ll T,n;
    cin>>T;
    while(T--) {
        cin>>n;
        ll cnt = 0;
        while(n>0) {
            n-=++cnt;
        }
        if(n==-1) {
            cnt++;
        }
        cout<<cnt<<endl;
    }
    return 0;
}


