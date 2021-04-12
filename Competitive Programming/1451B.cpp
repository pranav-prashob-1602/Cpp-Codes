#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

int main() {
    ll T,N,q,a,b;
    cin>>T;
    while(T--) {
        cin>>N>>q;
        string s;
        cin>>s;
        ll z = count(s.begin(),s.end(),'0');
        ll o = count(s.begin(),s.end(),'1');
        while(q--) {
            cin>>a>>b;
            ll p = count(s.begin(),s.begin()+a-2,s[a-1]);
            ll q = count(s.begin()+b,s.end(),s[b-1]);
            if(p>0 || q>0) {
                cout<<"YES"<<endl;
            } else {
                cout<<"NO"<<endl;
            }
        }
    }
    return 0;
}


