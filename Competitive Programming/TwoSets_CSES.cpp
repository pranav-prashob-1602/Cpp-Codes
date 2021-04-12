#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

int main() {
    ll n;
    cin>>n;
    ll sum = n*(n+1)/2;
    if(sum%2) {
        cout<<"NO"<<endl;
    }else {
        cout<<"YES"<<endl;
        vector<bool> num(n,false);
        sum/=2;
        for(ll i=n-1;i>=0;i--) {
            if(sum-(i+1)>=0) {
                num[i] = true;
                sum-=(i+1);
            }

        }
        ll cnt = count(num.begin(),num.end(),false);
        cout<<n-cnt<<endl;
        for(ll i=0;i<n;i++) {
            if(num[i]) {
                cout<<i+1<<" ";
            }
        }
        cout<<endl;
        cout<<cnt<<endl;
        for(ll i=0;i<n;i++) {
            if(!num[i]) {
                cout<<i+1<<" ";
            }
         }
    }
    return 0;
}



