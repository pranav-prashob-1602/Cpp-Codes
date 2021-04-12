#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) begin(x), end(x)

#define sz(x) (int)(x).size()

#define ff first
#define ss second

#define mp make_pair

#define ll long long
#define ld long double

int main() {
    ll T,n,m,x;
    cin>>T;
    while(T--) {
        cin>>n;
        ll m1 = 0,m2=0,sum=0;
        while(n--) {
            cin>>x;
            sum+=x;
            m1 = max(m1,sum);
        }
        cin>>m;
        sum=0;
        while(m--) {
            cin>>x;
            sum+=x;
            m2 = max(m2,sum);
        }
        cout<<m1+m2<<endl;
    }
    return 0;
}


