#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

int main() {
    ll T,n,m;
    cin>>T;
    while(T--) {
        cin>>n>>m;
        if(pow(m,2)<=n && n%2==m%2) {
            cout<<"YES"<<endl;
        }else {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}


