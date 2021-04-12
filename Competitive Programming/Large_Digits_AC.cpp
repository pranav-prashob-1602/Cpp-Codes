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
    string s1,s2;
    cin>>s1>>s2;
    ll a,b;
    a=b=0;
    for(ll i =0;i<s1.length();i++) {
        a+=s1[i]-'0';
    }
    for(ll i =0;i<s2.length();i++) {
        b+=s2[i]-'0';
    }
    cout<<max(a,b);
    return 0;
}



