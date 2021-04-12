#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

int main() {
    ll n,m;
    cin>>m;
    n=m;
    m-=2;
    ll x=2,k=2;
    cout<<x<<" ";
    while(m--) {
        x = (x+k)%n;
        if(x==0) {
            x=n;
        }
        cout<<x<<" ";
        k++;
    }
    return 0;
}



