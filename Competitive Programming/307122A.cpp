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
    ll n;
    string s = "";
    cin>>n;
    for(int i=0;i<n/2;i++) {
        if(i%2) {
            s+="bb";
        }else {
            s+="aa";
        }
    }
    if(n%2) {
        if((n/2) %2 == 0) {
            s+='a';
        }else {
            s+='b';
        }
    }
    cout<<s<<endl;
    return 0;
}


