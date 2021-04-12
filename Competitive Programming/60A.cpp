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
    ll n,m,x;
    cin>>n>>m;
    ll left=1,right=n;
    for(int i=0;i<m;i++) {
        string s,b;
        cin>>s>>s>>s>>b>>x;
        if(s[0]=='l') {
            right = min(right,x-1);
        }else {
            left = max(left,x+1);
        }
    }
    if(right>=left) {
        cout<<right-left+1<<endl;
    }else {
        cout<<-1<<endl;
    }
    return 0;
}


