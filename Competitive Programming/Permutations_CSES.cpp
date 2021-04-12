#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
/*
4 ke liye
2 4 1 3
5 ke kiye
5 2 4 1 3
*/
int main() {
    ll n;
    cin>>n;
    if(n<=3) {
        if(n!=1) {
            cout<<"NO SOLUTION";
            return 0;
        }
        cout<<1;
        return 0;
    }
    ll x = n/2;
    if(n%2) {
        cout<<n--<<" ";
    }
    while(x>0) {
        cout<<x--<<" "<<n--<<" ";
    }
    return 0;
}



