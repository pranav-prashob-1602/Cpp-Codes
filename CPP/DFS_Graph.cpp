#include<bits/stdc++.h>

using namespace std;

int n = 7;

typedef struct Node {
    int v,e;
    int **adj;
}graph;

int ** adjMatrix() {
    int u,v,i;
    graph *g = NULL;
    g = (graph*)malloc(sizeof(graph));
    //if(g==NULL) {
        //printf("Error in allocating memory\n\n");
        //return;
    //}
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
    return g->adj;
}

static vector<int> visited(n);

void DFS(int **g,int start,int n) {
    int j;
    if(visited[start] == 0) {
        cout<<start<<" ";
        visited[start] = 1;
        for(j=1;j<n;j++) {
            if(g[start][j] && !visited[j]) {
                DFS(g,j,n);
            }
        }
    }
}

int main() {
    int **g = adjMatrix();
    int n;
    while(true) {
        cout<<"\nEnter the starting node : (0 for exit)";
        cin>>n;
        fill(visited.begin(),visited.end(),0);
        if(n==0) {
            break;
        }
        DFS(g,n,7);
    }
    return 0;
}
