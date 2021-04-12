#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

int main() {
    ll T,n,a,b,h;
    cin>>T;
    while(T--) {
        string s;
        cin>>n>>a>>b>>h;
        cin>>s;
        ll o,z;
        o = count(s.begin(),s.end(),'1');
        z = n-o;
        if(o==0) {
            ll res = z*a;
            ll x = h*z + z*b;
            cout<<min(res,x)<<endl;
        }else if(z==0) {
            ll res = o*b;
            ll x = h*o + o*a;
            cout<<min(res,x)<<endl;
        }else {
                ll res = o*b + z*a;
                ll x = h*o + (z+o)*a;
                ll y = h*z + (z+o)*b;
                cout<<min(res,min(x,y))<<endl;
        }
    }
    return 0;
}


