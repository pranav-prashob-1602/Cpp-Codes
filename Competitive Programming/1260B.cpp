#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

int main() {
    ll T,N,c,s;
    cin>>T;
    while(T--) {
        cin>>c>>s;
        if(c>s) {
            swap(c,s);
        }
        if((c+s)%3==0 && c>=s/2) {
            cout<<"YES"<<endl;
        }else {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
