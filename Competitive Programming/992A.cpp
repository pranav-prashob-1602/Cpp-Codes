#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) begin(x), end(x)

#define sz(x) (int)(x).size()

#define f first
#define s second

#define mp make_pair

#define ll long long
#define ld long double

int main() {
    ll a,b;
    cin>>a>>b;
    if(b==0) {
        cout<<"No";
    }else if(b==1) {
        if(a==0) {
            cout<<"Yes";
        }else {
            cout<<"No";
        }
    }else if(a-b+1<0) {
        cout<<"No";
    }else {
        if((a-b+1)%2) {
            cout<<"No";
        }else {
            cout<<"Yes";
        }
    }
    return 0;
}


