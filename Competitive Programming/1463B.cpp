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
    ll T,n,x;
    cin>>T;
    while(T--) {
        cin>>n;
        ll s1,s2;
        s1=s2=0;
        vector<ll> v;
        for(int i=0;i<n;i++) {
            cin>>x;
            v.pb(x);
            if(i%2) {
                s1+=x;
            }else {
                s2+=x;
            }
        }
        bool flag = false;
        if(s1>s2) {
            flag = true;
        }
        for(int i=0;i<n;i++) {
            if(i%2 && flag) {
                cout<<v[i]<<" ";
            }else if(i%2==0 && !flag) {
                cout<<v[i]<<" ";
            }else {
                cout<<1<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}


