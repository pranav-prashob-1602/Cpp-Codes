#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

int main() {
    ll T,n,k;
    cin>>T;
    while(T--) {
        cin>>n>>k;
        ll a[n];
        for(int i=1;i<=n;i++) {
            if(i%2) {
                a[i-1] = -i;
            }else {
                a[i-1] = i;
            }
        }
        ll cnt = 0;
         ll d = k - (n/2);
        if(d>0) {
            for(int i=n-1;i>=0;i--) {
                if(a[i]<0) {
                    a[i] = -a[i];
                    d--;
                }
                if(d==0) {
                    break;
                }
            }
        }else if(d<0){
            for(int i=n-1;i>=0;i--) {
                if(a[i]>0) {
                    a[i] = -a[i];
                    d++;
                }
                if(d==0) {
                    break;
                }
            }
        }
        for(int i=0;i<n;i++) {
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}


