#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

int main() {
    ll T,n,m,x,z;
    cin>>T;
    while(T--) {
        cin>>n>>m;
        x = abs(n-m);
        if(x%10==0) {
            cout<<x/10<<endl;
        }else {
            z = x/10;
            cout<<z+1<<endl;
        }
    }
    return 0;
}



