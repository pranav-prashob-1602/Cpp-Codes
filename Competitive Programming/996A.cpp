#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) begin(x), end(x)

#define sz(x) (int)(x).size()

#define ff first
#define ss second

#define mp make_pair

#define ll long long
#define ld long double

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n,x;
    cin>>n;
    ll cnt=0;
    while(n!=0) {
        if(n/100>0) {
            x = n/100;
            n = n%100;
        }else if(n/20>0) {
            x = n/20;
            n = n%20;
        }else if(n/50>0) {
            x = n/50;
            n = n%50;
        }else if(n/10>0) {
            x = n/10;
            n = n%10;
        }else if(n/5>0) {
            x = n/5;
            n = n%5;
        }else {
            x = n;
            n=0;
        }
        cnt+=x;
    }
    cout<<cnt;
    return 0;
}


