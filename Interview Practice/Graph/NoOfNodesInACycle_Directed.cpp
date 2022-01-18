#include<bits/stdc++.h>

using namespace std;

int main() {
    int n,m,x,y;
    cin>>n>>m;
    vector<int> g[n];
    vector<int> g1[n];
    while(m--) {
        cin>>x>>y;
        g[x].push_back(y);
        g1[y].push_back(x);
    }
    vector<int> odeg(n, 0), ideg(n, 0);
    for(int i=0;i<n;i++) {
        for(auto& u : g[i]) {
            ideg[u]++;
        }
        odeg[i]=g[i].size();
    }
    vector<bool> vis(n, false);
    while(true) {
        queue<int> q;
        for(int i=0;i<n;i++) {
            if((ideg[i]+odeg[i]<=1 || (ideg[i]==0 && odeg[i]>0) || (odeg[i]==0 && ideg[i]>0)) && vis[i]==false) {
                q.push(i);
            }
        }
        if(q.empty()) {
            break;
        }
        while(!q.empty()) {
            int u=q.front();
            q.pop();
            odeg[u]=0;
            vis[u]=true;
            for(auto& v : g[u]) {
                ideg[v]--;
            }
            for(auto& v : g1[u]) {
                odeg[v]--;
            }
        }
    }
    int res=count(vis.begin(), vis.end(), false);
    cout<<res<<endl;
    return 0;
}
