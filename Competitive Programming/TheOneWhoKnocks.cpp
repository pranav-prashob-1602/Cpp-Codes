#include<bits/stdc++.h>

using namespace std;

#define ll long long

struct MyCmp

int main() {
    ll T,N,min_x;
    cin>>T;
    while(T--) {
        cin>>N;
        int a[N];
        ll min_val = INT_MAX;
        ll min_ind = -1;
        for(int i=0;i<N;i++) {
            cin>>a[i];
            if(a[i]<min_val) {
                min_val = a[i];
                min_ind = i;
            }
        }
        for(int i=0;i<N;i++) {
            int y = min_val+abs(i-min_ind);
            int x = min(y,a[i]);
            cout<<x<<" ";
        }
        cout<<endl;
    }
    return 0;
}
