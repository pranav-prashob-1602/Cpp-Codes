#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

int main() {
    ll T,n;
    cin>>T;
    while(T--) {
        cin>>n;
        if(n==1) {
            cout<<-1<<endl;
            continue;
        }
        cout<<2;
        for(int i=1;i<n;i++) {
            cout<<3;
        }
        cout<<endl;
    }
    return 0;
}


