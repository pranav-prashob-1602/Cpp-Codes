#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

int main() {
    ll N,sum=0;
    cin>>N;
    ll a[N],b[N];
    for(int i=0;i<N;i++) {
        cin>>a[i];
    }
    for(int i=0;i<N;i++) {
        cin>>b[i];
        sum+=(b[i]-a[i]);
    }
    sum=sum/N;
    for(int i=0;i<N;i++) {
        ll y = b[i]-a[i];
        if(y<=sum) {
            cout<<i<<" ";
        }
    }
    return 0;
}


