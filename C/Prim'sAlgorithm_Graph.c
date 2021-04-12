#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>

#define mx 6

typedef struct Node {
    int v,e;
    int **adj;
}graph;

graph *adjMatrix() {
    int u,v,i,w;
    graph *g = NULL;
    g = (graph*)malloc(sizeof(graph));
    if(g==NULL) {
        printf("Error in allocating memory\n\n");
        return g;
    }
    printf("\nEnter the number of vertices and edges :");
    scanf("%d%d",&g->v,&g->e);
    g->adj = (int**) malloc((g->v)*sizeof(int *));
    for(u=0;u<g->v;u++) {
        g->adj[u] = (int*)malloc((g->v)*sizeof(int));
        for(v=0;v<g->v;v++) {
            g->adj[u][v] = 0;
        }
    }
    printf("\nEnter the Node Numbers for the pair of edges :\n");
    for(i=0;i<g->e;i++) {
        scanf("%d%d%d",&u,&v,&w);
        g->adj[u][v] = w;
        g->adj[v][u] = w;
    }
    printf("\nThe Adjacency matrix formed is :\n");
    for(u=0;u<g->v;u++) {
        for(v=0;v<g->v;v++) {
            printf("%d ",g->adj[u][v]);
        }
        printf("\n");
    }
    return g;
}

int min_key(int key[],bool minSpanTree[]) {
    int i,m_key = INT_MAX,m_ind = mx;
    for(i=0;i<mx;i++) {
        if(!minSpanTree[i] && key[i] < m_key) {
            m_key = key[i];
            m_ind = i;
        }
    }
    return m_ind;
}

void print(int parent[],graph * g) {
    int i;
    printf("\nEdge\tWeight\n");
    for(i=1;i<mx;i++) {
        printf("%d-%d\t%d\n",parent[i],i,g->adj[i][parent[i]]);
    }
}

void prims(graph* g) {
    int i,key[mx],parent[mx],count=0,u,v;
    bool minSpanTree[mx];
    for(i=0;i<mx;i++) {
        key[i] = INT_MAX;
        minSpanTree[i] = false;
    }
    key[0] = 0;
    parent[0] = -1;
    for(i=0;i<mx;i++) {
        u = min_key(key,minSpanTree);
        minSpanTree[u] = true;
        for(v=0;v<mx;v++) {
            if(g->adj[u][v] && !minSpanTree[v] && g->adj[u][v]<key[v]) {
                parent[v] = u;
                key[v] = g->adj[u][v];
            }
        }
    }
    print(parent,g);
}

int main() {
    graph *g = adjMatrix();
    prims(g);
    return 0;
}
