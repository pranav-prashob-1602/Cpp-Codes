#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ll T,N,K;
    cin>>T;
    while(T--) {
        cin>>N;
        ll a[N];
        for(int i=0;i<N;i++) {
            cin>>a[i];
        }
        sort(a,a+N,greater<int> ());
        ll sum = 0;
        for(int i=0;i<N;i++) {
            sum+=a[i];
        }
        if(sum==0) {
            cout<<"NO"<<endl;
        }else {
            cout<<"YES"<<endl;
            if(sum<0) {
                sort(a,a+N);
            }
            for(int i=0;i<N;i++) {
                if(a[i]!=0) {
                    cout<<a[i]<<" ";
                }
            }
            for(int i=0;i<N;i++) {
                if(a[i]==0) {
                    cout<<a[i]<<" ";
                }
            }
            cout<<endl;
        }
    }
    return 0;
}


