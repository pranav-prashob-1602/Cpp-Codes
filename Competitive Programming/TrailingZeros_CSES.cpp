#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

int main() {
    ll N;
    cin>>N;
    ll cnt=0;
    while(N>=5) {
        N=N/5;
        cnt+=N;
    }
    cout<<cnt;
    return 0;
}



