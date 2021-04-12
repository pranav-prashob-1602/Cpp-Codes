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

ll dectobin(ll x) {
    ll p=1,z;
    string res;
    while(x!=0) {
        z = x%2;
        x/=2;
        res += z+'0';
    }
    reverse(res.begin(),res.end());
    return atoi(res.c_str());
}

int main() {
    ll T,n,cnt=0;
    string str;
    cin>>n;
    ll i=1;
    while(dectobin(i)<=n) {
        i++;
        cnt++;
    }
    cout<<cnt;
    return 0;
}


