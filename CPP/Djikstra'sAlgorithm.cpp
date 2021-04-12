#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) begin(x), end(x)

#define sz(x) (int)(x).size()

#define f first
#define s second

#define mp make_pair

#define ll long long
#define ld long double

#define V 9

int minDist(int *dist,bool *destin) {
    int min_d = INT_MAX,min_ind;
    for(int i=0;i<V;i++) {
        if(!destin[i] && dist[i]<=min_d) {
            min_d = dist[i];
            min_ind = i;
        }
    }
    return min_ind;
}

void display(int *dist) {
    for(int i=0;i<V;i++) {
        cout<<i<<" "<<dist[i]<<endl;
    }
}

void Dijkstra(int graph[V][V],int src) {
    int dist[V];
    bool destin[V];      // whether or not the vertex is included in the path or not
    for(int i=0;i<V;i++) {
        dist[i] = INT_MAX;
        destin[i] = false;
    }
    dist[src] = 0;
    for(int i=0;i<V-1;i++) {
        int u = minDist(dist,destin);
        destin[u] = true;
        for(int j=0;j<V;j++) {
            if(!destin[j] && graph[u][j] != 0 && dist[u] != INT_MAX && dist[u]+graph[u][j] < dist[j]) {
                dist[j] = dist[u]+graph[u][j];
            }
        }
    }
    display(dist);
}

int main() {
    int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
    Dijkstra(graph,0);
    return 0;
}

