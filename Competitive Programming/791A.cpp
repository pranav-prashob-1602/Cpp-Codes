#include<bits/stdc++.h>

/*

shinchanCoder Here!!

*/

using namespace std;

#define pb push_back
#define all(x) begin(x), end(x)

#define sz(x) (int)(x).size()

#define ff first
#define ss second

#define mp make_pair

#define ll long long
#define ld long double

#define mod 1000000007

map<string,ll> m;

ll getVal(string s1,string s2) {
    if(m[s1]==0 || m[s2]==0) {
        return INT_MAX;
    }else {
        return m[s1]+m[s2];
    }
}

int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll a,b;
    cin>>a>>b;
    ll cnt = 0;
    while(a<=b) {
        a*=3;
        b*=2;
        cnt++;
    }
    cout<<cnt;
    return 0;
}


