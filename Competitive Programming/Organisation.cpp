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
    ll T,n,k,x;
    cin>>T;
    while(T--) {
        vector<pair<ll,ll>> v;
        cin>>n>>k;
        for(int i=0;i<=n;i++) {
            cin>>x;
            v.pb(mp(x,i));
        }
        ll c1,m1,c2,m2;
        int j=n;
        for(int i=0;i<n;i++) {
            c1 = v[i].s;
            c2 = v[j].s;
            m2 = k-v[i].f;
            m1 = v[i].f;
            v[j].f = v[j].f - m2;
            cout<<c1<<" "<<m1<<" "<<c2<<" "<<m2<<endl;
            if(v[j].f==0) {
                j--;
            }
        }
    }
    return 0;
}


