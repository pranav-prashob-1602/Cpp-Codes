#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int v,e;
    int **adj;
}graph;

void adjMatrix() {
    int u,v,i;
    graph *g = NULL;
    g = (graph*)malloc(sizeof(graph));
    if(g==NULL) {
        printf("Error in allocating memory\n\n");
        return;
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
        scanf("%d%d",&u,&v);
        g->adj[u][v] = 1;
        g->adj[v][u] = 1;
    }
    printf("\nThe Adjacency matrix formed is :\n");
    for(u=0;u<g->v;u++) {
        for(v=0;v<g->v;v++) {
            printf("%d ",g->adj[u][v]);
        }
        printf("\n");
    }
}

int main() {
    adjMatrix();
    return 0;
}
