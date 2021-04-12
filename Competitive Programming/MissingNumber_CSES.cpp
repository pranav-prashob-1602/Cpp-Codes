#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

int main() {
    ll n,x;
    cin>>n;
    vector<bool> v(n,false);
    for(int i=0;i<n-1;i++) {
        cin>>x;
        v[x-1] = true;
    }
    for(int i=0;i<n;i++) {
        if(!v[i]) {
            cout<<i+1;
            break;
        }
    }
    return 0;
}




