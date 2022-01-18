/*
*
* https://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/problem/C
*
*/


#include<bits/stdc++.h>

#define ll int

using namespace std;

class Graph {
    int V;
    vector<ll> parent;
    vector<ll> rnk;
    vector<ll> score;
    vector<ll> pend_score;
    vector<vector<ll>> g;

public:

    Graph(int V) {
        this->V = V;
        parent = vector<ll> (V,  -1);
        rnk = vector<ll> (V, 1);
        score = vector<ll> (V, 0);
        pend_score = vector<ll> (V, 0);
        g = vector<vector<ll>> (V);
        for(ll i=0;i<V;i++) {
            g[i].push_back(i);
        }
    }

    /*
        DSU FUNCTIONS :
            1. Find
            2. Union
    */

    ll findSet(ll v) {
        if(parent[v]==-1) {
            return v;
        }
        return parent[v]=findSet(parent[v]);
    }

    void unionSet(ll s1, ll s2) {
        if(s1!=s2) {
            if(rnk[s1]>rnk[s2]) {
                for(auto& u : g[s2]) {
                    score[u]+=pend_score[s2]-pend_score[s1];
                    g[s1].push_back(u);
                }
                pend_score[s2]=0;
                g[s2].clear();
                parent[s2]=s1;
                rnk[s1]+=rnk[s2];
            }else {
                for(auto& u : g[s1]) {
                    score[u]+=pend_score[s1]-pend_score[s2];
                    g[s2].push_back(u);
                }
                pend_score[s1]=0;
                g[s1].clear();
                parent[s1]=s2;
                rnk[s2]+=rnk[s1];
            }
        }
    }

    void addScore(ll p, ll y) {
        pend_score[p]+=y;
    }

    ll getScore(ll x) {
        ll p = findSet(x);
        return score[x]+pend_score[p];
    }

};


int main() {
    ll n,m,x,y;
    string s;
    cin>>n>>m;
    Graph g(n);
    while(m--) {
        cin>>s;
        if(s=="add") {
            cin>>x>>y;
            x--;
            ll p = g.findSet(x);
            g.addScore(p, y);
        }else if(s=="join") {
            cin>>x>>y;
            x--;
            y--;
            ll p1 = g.findSet(x);
            ll p2 = g.findSet(y);
            if(p1!=p2) {
                g.unionSet(p1, p2);
            }
        }else {
            cin>>x;
            x--;
            cout<<g.getScore(x)<<"\n";
        }
    }

    return 0;
}

