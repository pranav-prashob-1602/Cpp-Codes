#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

int main() {
    ll T,N,q,a,b;
    cin>>T;
    while(T--) {
        cin>>N>>q;
        char s1[1000000],s2[1000000];
        cin>>s1>>s2;
        unordered_map<char,ll> m,m2;
        for(ll i=0;i<N;i++) {
            m[s1[i]]++;
            m2[s2[i]]++;
        }
        bool flag = true;
        for(ll i=0;i<N;i++) {
            if(m[s1[i]] != m2[s1[i]]) {
                if(m[s1[i]]%q!=0) {
                    flag = false;
                    break;
                }else if(q==1 && m[s1[i]]>1) {
                    flag = false;
                    break;
                }
            }
        }
        if(flag) {
            cout<<"Yes"<<endl;
        }else {
            cout<<"No"<<endl;
        }
    }
    return 0;
}


