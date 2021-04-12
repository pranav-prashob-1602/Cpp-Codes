#include<bits/stdc++.h>

using namespace std;

#define ll long long

bool isPrime(int n) {
    for(int i=2;i*i<=n;i++) {
        if(n%i==0) {
            return false;
        }
    }
    return true;
}


int main() {
    ll N;
    cin>>N;
    bool prm[N];
    for(int i=2;i<=N;i++) {
        prm[i] = isPrime(i);
    }
    ll ans = 0;
    for(int i=1;i<=N;i++) {
        ll count = 0;
        for(int j=2;j<=N;j++) {
            if(prm[j]) {
                if(i%j==0) {
                    count++;
                }
            }
        }
        if(count==2) {
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
