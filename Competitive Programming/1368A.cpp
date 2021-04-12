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
    ll T,a,b,n,cnt;
    cin>>T;
    while(T--) {
        cin>>a>>b>>n;
        cnt = 0;
        while(a<=n && b<=n) {
            if(a>b) {
                b+=a;
            }else {
                a+=b;
            }
            cnt++;
        }
        cout<<cnt<<endl;
    }
    return 0;
}


