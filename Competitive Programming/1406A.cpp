#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

int main() {
    ll T,n,x;
    cin>>T;
    while(T--) {
        cin>>n;
        bool a[200] = {false};
        bool b[200] = {false};
        ll p1=0,p2=0;
        while(n--) {
            cin>>x;
            if(!a[x]) {
                a[x] = true;
                while(a[p1]) {
                    p1++;
                }
            }else {
                b[x]=true;
                while(b[p2]) {
                    p2++;
                }
            }
        }
        cout<<p1+p2<<endl;
    }
    return 0;
}



