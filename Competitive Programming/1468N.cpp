#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) begin(x), end(x)

#define sz(x) (int)(x).size()

#define f first
#define s second

#define mp make_pair

#define ll long long
#define ld long double

int main() {
    ll T,n,x,m;
    cin>>T;
    while(T--) {
        ll c1,c2,c3,a[5];
        cin>>c1>>c2>>c3;
        for(int i=0;i<5;i++) {
            cin>>a[i];
        }
        c1 = c1-a[0];
        c2 = c2-a[1];
        c3 = c3-a[2];
        if(c1<0 || c2<0 || c3<0) {
            cout<<"NO"<<endl;
        }else {
            a[3] -=c1;
            a[4] -=c2;
            a[3] = a[3]<0 ? 0 : a[3];
            a[4] = a[4]<0 ? 0 : a[4];
            if(a[3]+a[4]>c3) {
                cout<<"NO"<<endl;
            }else {
                cout<<"YES"<<endl;
            }
        }
    }
    return 0;
}


