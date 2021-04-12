#include<bits/stdc++.h>

using namespace std;

typedef struct Node {
    int v,e;
    int **adj;
}graph;

void adjMatrix() {
    int u,v,i;
    graph *g = NULL;
    g = (graph*)malloc(sizeof(graph));
    if(g==NULL) {
        cout<<"Error in allocating memory\n\n";
        return;
    }
    cout<<"\nEnter the number of vertices and edges :";
    cin>>g->v>>g->e;
    g->adj = (int**) malloc((g->v)*sizeof(int *));
    for(u=0;u<g->v;u++) {
        g->adj[u] = (int*)malloc((g->v)*sizeof(int));
        for(v=0;v<g->v;v++) {
            g->adj[u][v] = 0;
        }
    }
    cout<<"\nEnter the Node Numbers for the pair of edges :\n";
    for(i=0;i<g->e;i++) {
        cin>>u>>v;
        g->adj[u][v] = 1;
        g->adj[v][u] = 1;
    }
    cout<<"\nThe Adjacency matrix formed is :\n";
    for(u=0;u<g->v;u++) {
        for(v=0;v<g->v;v++) {
            cout<<g->adj[u][v]<<" ";
        }
        cout<<endl;
    }
}

int main() {
    adjMatrix();
    return 0;
}
