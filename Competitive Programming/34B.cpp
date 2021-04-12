#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

int main() {
    ll N,M;
    cin>>N>>M;
    ll a[N];
    for(int i=0;i<N;i++) {
        cin>>a[i];
    }
    sort(a,a+N);
    ll sum = 0;
    for(int i=0;i<N;i++) {
        if(a[i]<0 && M>0) {
            sum+=a[i];
            M--;
        }
    }
    sum*=-1;
    cout<<sum<<endl;
    return 0;
}


