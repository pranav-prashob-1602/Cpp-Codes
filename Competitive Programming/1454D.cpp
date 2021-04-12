#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

int main() {
    ll T,n,x;
    cin>>T;
    while(T--) {
        cin>>n;
        x = 2;
        vector<ll> v;
        while(x<=n) {
            for(int i=x;i<=n;i++) {
                if(n%i==0) {
                    if(v.size()==0 || i%x==0) {
                        v.push_back(i);
                        n/=i;
                        if(v.size()==1) {
                            x=i;
                        }else {
                            x*=i;
                        }
                        break;
                    }
                }
            }
        }
        cout<<v.size()<<endl;
        for(auto& val : v) {
            cout<<val<<" ";
        }
        cout<<endl;
    }
    return 0;
}


