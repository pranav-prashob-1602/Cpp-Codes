#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) begin(x), end(x)

#define sz(x) (int)(x).size()

#define f first
#define s second

#define mp make_pair

#define ll long long
#define ld long double

int main() {
    ll L,R,T;
    cin>>T;
    while(T--) {
        cin>>L>>R;
        ll res = (2*L > R) ? R : -1;
        cout<<res<<endl;
    }
    return 0;
}


