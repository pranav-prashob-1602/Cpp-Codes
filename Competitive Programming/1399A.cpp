#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

int main() {
    ll T,n,x;
    cin>>T;
    while(T--) {
        cin>>n;
        vector<ll> v;
        for(int i=0;i<n;i++) {
            cin>>x;
            v.push_back(x);
        }
        sort(v.begin(),v.end());
        bool flag = true;
        for(int i=0;i<n-1;i++) {
            if(v[i+1]-v[i]>1) {
                flag = false;
                break;
            }
        }
        if(flag) {
            cout<<"YES"<<endl;
        }else {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}



