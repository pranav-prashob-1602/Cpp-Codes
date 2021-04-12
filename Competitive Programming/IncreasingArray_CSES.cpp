#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

int main() {
    ll n;
    cin>>n;
    ll a[n];
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    ll sum = 0;
    for(int i=0;i<n-1;i++) {
        if(a[i]>a[i+1]) {
            sum+=a[i]-a[i+1];
            a[i+1] = a[i];
        }
    }
    cout<<sum;
    return 0;
}



