#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

int main() {
    ll T,N,k,x;
    vector<bool>::iterator it;
    cin>>T;
    while(T--) {
        cin>>N>>k;
        vector<bool> v(101,false);
        for(int i=0;i<N;i++) {
            cin>>x;
            v[x] = true;
        }
        ll cnt = count(v.begin(),v.end(),false);
        if(cnt<=k) {
            cout<<k+(101-cnt)<<endl;
            continue;
        }
        ll z = 1;
        while(k!=0) {
            if(!v[z]) {
                v[z] = true;
                k--;
            }
            z++;
        }
        it = find(v.begin()+1,v.end(),false);
        cout<<it-v.begin()-1<<endl;
    }
    return 0;
}


