#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

ll powerCalc(ll i,ll m,ll K,ll s) {
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
        ll mag=0,irn=0,cnt=0,sht;
        while(irn<N && mag<N) {
            if(s[mag]=='M') {
                if(s[irn]=='I') {
                    ll x = irn>mag ? irn : mag;
                    ll y = irn>mag ? mag : irn;
                    sht = count(s.begin()+y,s.begin()+x,':');
                    if(powerCalc(irn,mag,K,sht)>0) {
                        cnt++;
                        irn++;
                        mag++;
                    }else {
                        if(mag>irn) {
                            irn++;
                        }else {
                            mag++;
                        }
                    }
                }else if(s[irn]=='X') {
                    mag = irn;
                    irn++;
                    mag++;
                }else {
                    irn++;
                }
            }else if(s[mag]=='X') {
                irn = mag;
                irn++;
                mag++;
            }else {
                mag++;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}



