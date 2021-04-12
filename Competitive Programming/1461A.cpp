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

ll calc(char a[][500],int i,int j,int k,int n) {
    if(i==n) {
        return 0;
    }
    bool flag = true;
    for(int p=j-k;p<=j+k;p++) {
        flag&=(a[i][p]=='*');
    }
    if(!flag) {
        return 0;
    }
    return 1 + calc(a,i+1,j,k+1,n);
}

int main() {
    ll T,n,m;
    cin>>T;
    while(T--) {
        cin>>n>>m;
        ll res = 0;
        vector<vector<ll>> v(n);
        char mt[n][500];
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                cin>>mt[i][j];
                if(mt[i][j]=='*') {
                    res++;
                }else {
                    v[i].pb(j);
                }
            }
        }
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(mt[i][j]=='*') {
                        ll x = calc(mt,i+1,j,1,n);
                        //if(x!=1) {
                            res+=x;
                        //}
                    }
                }
        }
        cout<<res<<endl;
    }
    return 0;
}


