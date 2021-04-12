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
    ll T,a,b,c;
    cin>>T;
    while(T--) {
        cin>>a>>b>>c;
        ll z = min(a,min(b,c));
        if((a+b+c)%9==0 && z>=(a+b+c)/9) {
            cout<<"YES"<<endl;
        }else {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}


