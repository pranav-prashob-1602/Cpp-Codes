#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ll N,a[100],x,y;
    cin>>N;
    for(int i=1;i<N;i++) {
        cin>>a[i];
    }
    cin>>x>>y;
    ll sum = 0;
    for(int i=x;i<y;i++) {
        sum+=a[i];
    }
    cout<<sum;
    return 0;
}
