#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ll T,N,K;
    cin>>T;
    while(T--) {
        cin>>N>>K;
        ll a[N];
        for(int i=0;i<N;i++) {
            cin>>a[i];
        }
        sort(a,a+N);
        ll sum = 0;
        for(int i=N-K-1;i<N;i++) {
            sum+=a[i];
        }
        cout<<sum<<endl;
    }
    return 0;
}


