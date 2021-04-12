#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

ll fun() {
    ll n;
    cin>>n;
    ll cnt = 0;
    while(n!=1) {
        if(n%3!=0) {
            return -1;
        }
        if(n%6==0) {
            n/=6;
        }else {
            n*=2;
        }
        cnt++;
    }
    return cnt;
}

int main() {
    ll T;
    cin>>T;
    while(T--) {
        cout<<fun()<<endl;
    }
    return 0;
}


