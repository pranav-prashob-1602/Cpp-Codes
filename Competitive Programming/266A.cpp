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
    ll n,cnt=0;
    string s;
    cin>>n>>s;
    for(int i=0;i<n-1;i++) {
        if(s[i]==s[i+1]) {
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}


