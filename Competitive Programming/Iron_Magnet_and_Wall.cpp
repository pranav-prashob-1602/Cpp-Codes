#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

ll powerCalc(ll i,ll m,ll K,ll s) {
    if(i==-1 || m == -1) {
        return -1;
    }
    ll p = K + 1 - abs(i - m) - s;
    return p;
}

int main() {
    ll N,T,K;
    cin>>T;
    while(T--) {
        cin>>N>>K;
        string s;
        cin>>s;
        ll mag=-1,irn=-1,cnt=0,sht=0;
        for(ll i=0;i<N;i++) {
            if(s[i]=='I') {
                irn = i;
            }else if(s[i]=='M') {
                mag = i;
            }else if(s[i]==':') {
                    sht++;
            }else if(s[i]=='X') {
                mag = -1;
                irn = -1;
            }
            if(powerCalc(irn,mag,K,sht)>0) {
                    sht=0;
                    cnt++;
                    mag = -1;
                    irn = -1;
            }else {
                if(s[i]=='M') {
                    irn = -1;
                }else if(s[i]=='I'){
                    mag = -1;
                }
                sht = 0;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}


