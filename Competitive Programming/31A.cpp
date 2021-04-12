#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

int main() {
    ll N;
    cin>>N;
    ll a[N];
    for(int i=0;i<N;i++) {
        cin>>a[i];
    }
    for(int i=0;i<N;i++) {
        for(int j=0;j<N-1;j++) {
            for(int k=j+1;k<N;k++) {
                if(a[j]+a[k] == a[i]) {
                    cout<<i+1<<" "<<k+1<<" "<<j+1;
                    return 0;
                }
            }
        }
    }
    cout<<-1;
    return 0;
}


