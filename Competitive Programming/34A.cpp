#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

int main() {
    ll N;
    cin>>N;
    ll arr[N];
    for(int i=0;i<N;i++) {
        cin>>arr[i];
    }
    ll diff = INT_MAX;
    int a,b;
    for(int i=0;i<=N;i++) {
        ll x = abs(arr[(i+1)%N] - arr[i%N]);
        if(diff>x) {
            diff = x;
            a = i%N + 1;
            b = (i+1)%N + 1;
        }
    }
    cout<<a<<" "<<b;
    return 0;
}


