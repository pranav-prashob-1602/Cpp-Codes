#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

int main() {
    ll T,n,x,y,d,res,ans;
    cin>>T;
    while(T--) {
        cin>>n>>x>>y>>d;
        res = INT_MAX;
        if(abs(x-y)%d==0) {
            res = abs(x-y)/d;
        }
        if((y-1)%d==0) {
            ans = (x+d-1)/d;
            ans+=(y-1)/d;
            res = min(res,ans);
        }
        if((n-y)%d==0) {
            ans = (n-x+d-1)/d;
            ans+=(n-y)/d;
            res = min(res,ans);
        }
        res = res == INT_MAX ? -1 : res;
        cout<<res<<endl;
    }
    return 0;
}





