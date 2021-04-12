#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

int main() {
    ll T,N;
    cin>>T;
    while(T--) {
        cin>>N;
        string s;
        cin>>s;
        ll a=0,b=0;
        for(int i=0;i<N;i++) {
            if(s[i]=='a') {
                a++;
                continue;
            }
            b++;
        }
        ll x;
        if(b==0) {
            x = (N/a);
        }else {
            x = (N/a) - N%b;
        }
        x = x%1000000007;
        cout<<x<<endl;
    }
    return 0;
}


