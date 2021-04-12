#include<bits/stdc++.h>

using namespace std;

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

struct Queue {
    int data;
    struct Queue* next;
}*frnt,*rear;

int isEmpty() {
    return frnt==NULL;
}

void enqueue(int n) {
    Queue *temp = new Queue();
    temp->next = NULL;
    temp->data = n;
    if(frnt==NULL) {
        frnt = rear = temp;
        return;
    }
    rear->next = temp;
    rear = rear->next;
}

int dequeue() {
    int d = -1;
    if(frnt==NULL) {
        cout<<"Underflow!!"<<endl;
    }else {
        Queue *temp = frnt;
        d  = temp->data;
        frnt = frnt->next;
        delete(temp);
    }
    return d;
}

void display() {
    if(frnt == NULL) {
        cout<<"\nNo data to show!"<<endl;
        return;
    }
    Queue *temp = frnt;
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

void BFS(int **g,int start,int n) {
    int visited[n] = {0};
    int i = start,j;
    cout<<i<<" ";
    visited[i] = 1;
    enqueue(i);
    while(!isEmpty()) {
        i = dequeue();
        for(j=1;j<n;j++) {
            if(g[i][j] && !visited[j]) {
                cout<<j<<" ";
                visited[j] = 1;
                enqueue(j);
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
        if(n==0) {
            break;
        }
        BFS(g,n,7);
    }
    return 0;
}
