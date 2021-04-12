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
    ll T,n,sum,cnt,x;
    cin>>T;
    for(int i=1;i<=T;i++) {
        cin>>n>>sum;
        cnt=0;
        vector<ll> v;
        while(n--) {
            cin>>x;
            v.pb(x);
        }
        sort(all(v));
        for(auto& val : v) {
            if(sum-val < 0) {
                break;
            }
            sum-=val;
            cnt++;
        }
        cout<<"Case #"<<i<<": "<<cnt<<endl;
    }
    return 0;
}
