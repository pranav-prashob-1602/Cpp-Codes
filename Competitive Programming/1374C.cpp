#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ll T,N;
    cin>>T;
    while(T--) {
        cin>>N;
        string s;
        cin>>s;
        ll o=0,c=0,cnt=0;
        for(int i=0;i<N;i++) {
            if(s[i] == '(') {
                    o++;
            }else {
                if(o==0) {
                    cnt++;
                }
                o = o==0 ? 0 : o-1;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
