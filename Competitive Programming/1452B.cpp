#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

int main() {
    ll T,N,x,res1,res2;
    cin>>T;
    while(T--) {
        cin>>N;
        ll sum = 0;
        ll max_ele = 0;
        for(int i=0;i<N;i++) {
            cin>>x;
            sum+=x;
            max_ele = max(max_ele,x);
        }
        ll n = N-1;
        res1 = max_ele*n-sum;
        res2 = (n-sum%n)%n;
        cout<<max(res1,res2)<<endl;
    }
    return 0;
}


