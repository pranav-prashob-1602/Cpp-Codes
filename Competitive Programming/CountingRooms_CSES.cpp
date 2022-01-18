#include<bits/stdc++.h>

using namespace std;

char g[1001][1001];
bool v[1001][1001];

bool isValid(int i, int j, int n, int m) {
    return (i>=0 && i<n && j>=0 && j<m && g[i][j]=='.');
}

int dir[] = {-1, 0, 1, 0, -1};

void dfs(int i, int j, int n, int m) {
    v[i][j]=true;
    for(int k=0;k<4;k++) {
        int x=i+dir[k];
        int y=j+dir[k+1];
        if(v[x][y]==false && isValid(x, y, n, m)) {
            dfs(x, y, n, m);
        }
    }
}

int main() {
    int n,m;
    cin>>n>>m;
    string s;
    for(int i=0;i<n;i++) {
        cin>>s;
        for(int j=0;j<m;j++) {
            g[i][j]=s[j];
            if(s[j]=='#') {
                v[i][j]=true;
            }else {
                v[i][j]=false;
            }
        }
    }
    int res=0;
    char ch;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(v[i][j]==false && g[i][j]=='.') {
                res++;
                dfs(i, j, n, m);
            }
        }
    }
    cout<<res<<endl;
    return 0;
}
