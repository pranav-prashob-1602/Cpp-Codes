#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

int main() {
    ll T,n,x;
    cin>>T;
    while(T--) {
        cin>>n;
        ll  cnt_1 = 0,cnt=0;
        for(int i=0;i<n;i++) {
            cin>>x;
            if(x%2 != i%2) {
                if(i%2) {
                    cnt_1++;
                }else {
                    cnt++;
                }
            }
        }
        if(cnt_1 == cnt) {
            cout<<cnt<<endl;
        }else if(cnt!=cnt_1) {
            cout<<-1<<endl;
        }
    }
    return 0;
}


