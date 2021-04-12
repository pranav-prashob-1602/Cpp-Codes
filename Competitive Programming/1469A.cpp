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
    ll T;
    cin>>T;
    while(T--) {
        string s;
        cin>>s;
        ll n = s.length()-1;
        ll cnt = count(s.begin(),s.end(),'?');
        if(s[0]==')' || s[n]=='(') {
            cout<<"NO"<<endl;
        }else if(cnt%2) {
            cout<<"NO"<<endl;
        }else {
            cout<<"YES"<<endl;
        }
    }
    return 0;
}


