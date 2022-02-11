/*
*
*   https://youtu.be/GNbjsAJjrT8
*   Time Stamp : 38:30
*
*/


#include<bits/stdc++.h>

using namespace std;

vector<int> par;
vector<int> rnk;

int findParent(int v) {
    if(par[v]==-1) {
        return v;
    }
    return par[v]=findParent(par[v]);
}

int unionByRank(int u, int v, int k) {
    int p1=findParent(u);
    int p2=findParent(v);
    int sum=0;
    if(p1!=p2) {
        sum+=rnk[p1]*rnk[p2]*k;
        if(rnk[p1]>rnk[p2]) {
            par[p2]=p1;
            rnk[p1]+=rnk[p2];
        }else {
            par[p1]=p2;
            rnk[p2]+=rnk[p1];
        }
    }
    return sum;
}

int main() {
    int n,m,x,y,w;
    cin>>n>>m;
    vector<pair<int, pair<int, int>>> g;
    par=vector<int> (n+1, -1);
    rnk=vector<int> (n+1, 1);
    for(int i=0;i<m;i++) {
        cin>>x>>y>>w;
        g.push_back({w, {x, y}});
    }
    sort(g.begin(), g.end(), [] (pair<int, pair<int,int>> a, pair<int, pair<int, int>> b) -> bool {
            return a.first>b.first;
         });
    int res=0;
    for(int i=0;i<m;i++) {
//        cout<<g[i].first<<" "<<g[i].second.first<<"-"<<g[i].second.second<<endl;
        res+=unionByRank(g[i].second.first, g[i].second.second, g[i].first);
    }
    cout<<res<<endl;
    return 0;
}
