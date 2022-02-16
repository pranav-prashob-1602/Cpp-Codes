#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

int main() {
    ll N;
    cin>>N;
    ll a[N],s[N];
    for(int i=0;i<N;i++) {
        cin>>a[i];
        if(i==0) {
            s[i]=a[i];
            continue;
        }
        s[i] = s[i-1]+a[i];
    }
    ll count = 0;
    for(int i=0;i<N;i++) {
        if(s[i]==0) {
            count++;
        }
    }
    cout<<count;
    return 0;
}