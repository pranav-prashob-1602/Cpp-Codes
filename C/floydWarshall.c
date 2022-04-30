#include<stdio.h>
#include<stdlib.h>

#define V 4
#define INF 99999

typedef struct node
{
    int v,e;
    int **adj;
}graph;

void floydwarshall(graph *);
void printSol(int D[][V+1]);


graph* adj_matrix()
{
    int i,j,u,v,w;
    graph *g;
    g=(graph*)malloc(sizeof(graph));
    if(g==NULL)
    {
        printf("\nUnable to allocate memory for Graph");
        return g;
    }
    printf("Enter the no. of Vertices & Edges respectively: ");
    scanf("%d%d",&g->v,&g->e);
    g->adj=(int**)malloc((g->v+1)*sizeof(int*));
    for(i=1; i<=g->v; i++)
    {
        g->adj[i]=(int*)malloc((g->v+1)*sizeof(int));
        for(j=1; j<=g->v; j++)
        {
            if(i==j)
            {
                g->adj[i][j]=0;
            }
            else
            {
                g->adj[i][j]=INF;
            }
        }
    }
    printf("\n");

    for(i=1; i<=g->e; i++)
    {
        printf("\n\nEnter the Source, Destination & Weight for Edge no. %d:",i);
        scanf("%d%d%d",&u,&v,&w);
        g->adj[u][v]=w;
        // g->adj[v][u]=;
    }
    printf("\n\n\nAdjacency Matrix of the Graph:\n\n");
    for(i=1; i<=g->v; i++)
    {
        for(j=1; j<=g->v; j++)
        {
            printf("%d ",g->adj[i][j]);
        }
        printf("\n\n");
    }
    printf("\n");
    return g;
}




void floydwarshall(graph *G)
{
    int D[V+1][V+1];
    for(int i=1; i<=V; i++)
    {
        for(int j=1; j<=V; j++)
        {
            D[i][j]=G->adj[i][j];
        }
    }

    for(int k=1; k<=V; k++)
    {
        printf("D^%d:\n\n",k);
        printSol(D);
        for(int i=1; i<=V; i++)
        {
            for(int j=1; j<=V; j++)
            {
                if(k==2 || k==1 || k==0)
                {
                    printf("\n\ni=%d j=%d k=%d  D[i][k]=%d  D[k][j]=%d   D[i][j]=%d",i,j,k,D[i][k],D[k][j],D[i][j]);
                }
                if(D[i][k]+D[k][j]<D[i][j])
                {

                    D[i][j]= D[i][k] + D[k][j];
                }
            }
        }
        printf("\n\n");
    }
    printf("\nFollowing Matrices shows shortest distances between all pair of the vertices: \n\n");

    printSol(D);
}



void printSol(int D[][V+1])
{

    for(int i=1; i<=V; i++)
    {
        for(int j=1; j<=V; j++)
        {
            if(D[i][j]!=99999)
            {
                printf("%d\t",D[i][j]);
            }
            else
            {
                printf("~\t");
            }
        }
        printf("\n\n");
    }
}


int main()
{
    graph *g=adj_matrix();

    /*int G[V][V]= {{0,9,-4,INF},
        {6,0,INF,2},
        {INF,5,0,INF},
        {INF,INF,1,0}
    };*/

    floydwarshall(g);

    return 0;
}
