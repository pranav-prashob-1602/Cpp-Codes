#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ll T,N;
    cin>>T;
    while(T--) {
        cin>>N;
        for(int i=4*N;i>2*N;i-=2) {
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}
