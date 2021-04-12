#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ll T,n,d,x;
    cin>>T;
    while(T--)
    {
        cin>>n>>d;
        ll cnt = 0,cnt_1 = 0;
        for(int i=0;i<n;i++){
            cin>>x;
            if(x>=80 || x<=9) {
                cnt++;
            }else {
                cnt_1++;
            }
        }
        ll res = (cnt+d-1)/d + (cnt_1+d-1)/d;
        cout<<res<<endl;
    }
    return 0;
}
