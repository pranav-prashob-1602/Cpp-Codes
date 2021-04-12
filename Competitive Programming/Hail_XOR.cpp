#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

int main() {
    ll T,n,x,m;
    cin>>T;
    while(T--) {
        cin>>n>>x;
        vector<ll> v;
        ll cnt = 0;
        for(int i=0;i<n;i++) {
            cin>>m;
            v.push_back(m);
        }
        sort(v.begin(),v.end());
        ll p,q,r,s,f;
        for(ll i=0;i<n;i++) {
            if(x<1) {
                break;
            }
            if(v[i]==0) {
                continue;
            }
            for(ll k=31;k>-1;k--) {
                p = (1<<k);
                if(x<=0) {
                    break;
                }
                q = v[i]&p;
                if(q!=0) {
                    for(ll z=i+1;z<n;z++) {
                        if(x<=0) {
                            break;
                        }
                        f=0;
                        r = v[z]&p;
                        if(r!=0) {
                            x-=1;
                            v[i]^=p;
                            v[z]^=p;
                            f=1;
                            break;
                        }
                    }
                    if(f==0 && i!=n-1) {
                        if(x<=0) {
                            break;
                        }
                        v[i]^=p;
                        v[n-1]^=p;
                        x-=1;
                    }
                }
            }
        }
        if(n==2 && x%2) {
            v[n-2]^=1;
            v[n-1]^=1;
        }
        for(auto& val : v) {
            cout<<val<<" ";
        }
        cout<<endl;
    }
    return 0;
}


