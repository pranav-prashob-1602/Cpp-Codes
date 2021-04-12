#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

int main() {
    ll T,n,k,x;
    vector<ll> a;
    vector<ll>::iterator up;
    cin>>n>>k;
    for(int i=0;i<n;i++) {
        cin>>x;
        a.push_back(x);
    }
    sort(a.begin(),a.end());
    ll j = n-1,i=0,cnt = 0;
    while(i<=j) {
        if(a[i]+a[j]<=k) {
            j--;
            i++;
            cnt++;
        }else {
            j--;
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}


