#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

int fun(int n,int m) {
    if(n==0 || m==0) {
        return 0;
    }
    return (n%10)*(m%10) + fun(n/10,m/10);
}

int main() {
    int n,m,T;
    cin>>T;
    while(T--) {
        cin>>n>>m;
        cout<<fun(n,m);
    }
    return 0;
}


