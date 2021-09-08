#include<bits/stdc++.h>

using namespace std;

class Graph {
    int V;
    list<pair<int, int>> l;

public:

    Graph(int V) {
        this->V = V;
    }

    void addEdge(int u, int v) {
        l.push_back(make_pair(u, v));
    }

    /*
        DSU FUNCTIONS :
            1. Find
            2. Union
    */

    int findSet(int v, vector<int> parent) {
        if(parent[v]==-1) {
            return v;
        }
        return findSet(parent[v], parent);
    }

    void unionSet(int s1, int s2, vector<int>& parent) {
        if(s1!=s2) {
            parent[s2]=s1;
        }
    }

    bool contains_cycle() {
        vector<int> parent(V, -1);

        for(auto& edge : l) {
            int i=edge.first;
            int j=edge.second;
            int s1=findSet(i, parent);
            int s2=findSet(j, parent);
            if(s1!=s2) {
                unionSet(s1, s2, parent);
            }else {
                cout<<"Same parents of "<<i<<" "<<j<<" "<<s1<<endl;
                return true;
            }
        }
        return false;
    }

};


int main() {
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,0);


    if(g.contains_cycle()) {
        cout<<"YES"<<endl;
    }else {
        cout<<"NO"<<endl;
    }

    return 0;
}
