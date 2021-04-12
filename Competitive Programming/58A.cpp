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
    string s;
    cin>>s;
    ll n = s.length();
    string res = "hello";
    ll k=0;
    for(ll i=0;i<n;i++) {
        if(s[i]==res[k]) {
            k++;
        }
        if(k==5) {
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
    return 0;
}


