#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

int main() {
    ll T,N,x;
    cin>>T;
    while(T--) {
            cin>>N;
            set<ll> s;
            for(int i=0;i<N;i++) {
                cin>>x;
                s.insert(x);
            }
            if(s.size()==N) {
                cout<<"NO"<<endl;
            }else {
                cout<<"YES"<<endl;
            }
    }
    return 0;
}


