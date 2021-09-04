/*

There are N cities numbered 0 to N-1. You have to choose 2 cities
such that there is no path from first city to second city. You are
given information in the form of M pairs (X,Y) i.e there is an
undirected city between city X and city Y. Find out the number
of ways in which cities can be chosen.

Constraints :

1<= N <=1e5
1<= M <=1e5
0<= X,Y <= N-1

*/

#include<bits/stdc++.h>

using namespace std;

int fac(int n) {
    if(n<=1) {
        return 1;
    }
    return n*fac(n-1);
}

int nCr(int n, int r) {
    if(r>=n) {
        return 1;
    }
    return fac(n)/(fac(n-r)*fac(r));
}

class Graph {
    int V;
    list<pair<int,int>> l;

public:

    Graph(int v) {
        V=v;
    }

    void addEdge(int u, int v) {
        l.push_back({u, v});
    }

    int findSet(int u, vector<int>& parent) {
        if(parent[u]==-1) {
            return u;
        }
        return parent[u] = findSet(parent[u], parent);
    }

    void unionSet(int u, int v, vector<int>& parent, vector<int>& rnk) {
        int s1=findSet(u, parent);
        int s2=findSet(v, parent);
        if(s1!=s2) {
            if(rnk[s1]>rnk[s2]) {
                parent[s2]=s1;
                rnk[s1]+=rnk[s2];
            }else {
                parent[s1]=s2;
                rnk[s2]+=rnk[s1];
            }
        }
    }

    int noOfWays() {
        vector<int> parent(V, -1);
        vector<int> rnk(V, 1);

        for(auto& it : l) {
            unionSet(it.first, it.second, parent, rnk);
        }

        for(int i=0;i<V;i++) {
            cout<<parent[i]<<" ";
        }
        cout<<endl;
        for(int i=0;i<V;i++) {
            cout<<rnk[i]<<" ";
        }
        cout<<endl;

        int res=nCr(V, 2);
        int res1=0; //More efficient way
        for(int i=0;i<V;i++) {
            if(parent[i]==-1) {
                cout<<rnk[i]<<" "<<nCr(rnk[i], 2)<<endl;
                res-=nCr(rnk[i], 2);
            }
            res1+=V-rnk[parent[i]==-1 ? i : parent[i]];
        }
        return res1/2;
        return res;
    }

};

int main() {
    Graph g(9);
    g.addEdge(0,1);
    g.addEdge(1,3);
    g.addEdge(3,4);
    g.addEdge(2,6);
    g.addEdge(2,5);
    g.addEdge(7,8);
    cout<<g.noOfWays()<<endl;
    return 0;
}


