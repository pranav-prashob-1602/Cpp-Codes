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
    ll T,n;
    cin>>T;
    string s;
    while(T--) {
        cin>>n>>s;
        sort(all(s));
        if(m[s]!=0) {
            m[s] = min(m[s],n);
        }else {
            m[s]=n;
        }
    }
    ll ans = INT_MAX;
    if(m["A"]!=0 && m["B"]!=0 && m["C"]!=0) {
        ans = m["A"]+m["B"]+m["C"];
    }
    if(m["ABC"]!=0) {
        ans = min(ans,m["ABC"]);
    }
    ans = min(ans,getVal("AB","C"));
    ans = min(ans,getVal("AC","B"));
    ans = min(ans,getVal("BC","A"));
    ans = min(ans,getVal("AB","BC"));
    ans = min(ans,getVal("AC","BC"));
    ans = min(ans,getVal("AB","AC"));
    if(ans==INT_MAX) {
        ans = -1;
    }
    cout<<ans<<endl;
    return 0;
}


