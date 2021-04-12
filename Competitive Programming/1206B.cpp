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
    ll pos,neg,z;
    pos=neg=z=0;
    ll res=0;
    for(ll i=0;i<n;i++) {
        cin>>x;
        if(x>0) {
            pos++;
            res+=(x-1);
        }else if(x==0){
            z++;
        }else {
            neg++;
            res+=abs(x+1);
        }
    }
    if(neg%2==0) {
        res+=z;
    }else {
        if(z>0) {
            res+=z;
        }else {
            res+=2;
        }
    }
    cout<<res;
    return 0;
}



