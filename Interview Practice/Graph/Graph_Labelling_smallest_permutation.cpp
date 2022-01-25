#include<bits/stdc++.h>

using namespace std;

int main() {
    int n,m,x,y;
    cin>>n>>m;
    vector<int> g[n];
    vector<int> outdeg(n, 0);
    while(m--) {
        cin>>x>>y;
        g[y-1].push_back(x-1);
        outdeg[x-1]++;
    }
    vector<int> res(n);
    priority_queue<int> pq;
    for(int i=0;i<n;i++) {
        if(outdeg[i]==0) {
            pq.push(i);
        }
    }
//    cout<<"A";
    while(!pq.empty()) {
        int u=pq.top();
        pq.pop();
        res[u]=n;
        n--;
        for(auto& v : g[u]) {
            outdeg[v]--;
            if(outdeg[v]==0) {
                pq.push(v);
            }
        }
    }
//    cout<<"A";
    for(int i=0;i<res.size();i++) {
        cout<<res[i]<<" ";
    }
    return 0;
}
