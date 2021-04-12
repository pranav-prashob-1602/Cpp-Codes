#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

int main() {
    ll n,x;
    cin>>n;
    set<ll> s;
    while(n--) {
        cin>>x;
        s.insert(x);
    }
    cout<<s.size();
    return 0;
}


