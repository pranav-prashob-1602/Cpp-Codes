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
    vector<string> v;
    string s;
    int n,m;
    cin>>n>>m;
    ll x = n;
    while(x--) {
        cin>>s;
        v.pb(s);
    }
    bool col = true,flag = false;
    ll res = 0;
    for(int i=0;i<n;i++) {
        flag = false;
        for(int j=0;j<m;j++) {
            col = true;
            for(int k=0;k<n;k++) {
                col &= (v[k][j] <= v[i][j]);
            }
            flag|=col;
        }
        if(flag) {
            res+=1;
        }
    }
    cout<<res<<endl;
    return 0;
}


