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
        while(n--) {
            cin>>x;
            v.push_back(x);
        }
        sort(v.begin(),v.end());
        if(v[0] == v[v.size()-1]) {
            cout<<v.size()<<endl;
        }else {
            cout<<1<<endl;
        }
    }
    return 0;
}


