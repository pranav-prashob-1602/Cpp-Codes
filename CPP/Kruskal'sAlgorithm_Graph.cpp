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

class Edge {
public:
    int src,dst,wgt;
    void setData(int s,int d,int w) {
        src = s;
        dst = d;
        wgt = w;
    }
    int getSrc() {
        return src;
    }
    int getDst() {
        return dst;
    }
    int getWgt() {
        return wgt;
    }
};

bool compare(Edge e1,Edge e2) {
    return e1.wgt<e2.wgt;
}

int findPrt(int x,int p[]) {
    if(p[x]==x) {
        return x;
    }
    findPrt(p[x],p);
}

void display(Edge mst[],int n) {
    int tot_wgt = 0;
    cout<<"Source\tDestination\tWeight"<<endl;
    for(int i=0;i<n-1;i++) {
        cout<<mst[i].src<<"\t\t"<<mst[i].dst<<"\t\t"<<mst[i].wgt<<endl;
        tot_wgt+=mst[i].wgt;
    }
    cout<<"Minimum Weight : "<<tot_wgt<<endl;
}

void kruskal(Edge edge[],int e,int n) {
    sort(edge,edge+e,compare);
    Edge mst[n-1];
    int *parent = new int(n);
    int cnt=0;
    for(int i=0;i<n;i++) {
        parent[i] = i;
    }
    int i=0;
    while(cnt!=n-1) {
        Edge cur = edge[i];
        int s_prt,d_prt;
        s_prt = findPrt(cur.src,parent);
        d_prt = findPrt(cur.dst,parent);
        if(s_prt!=d_prt) {
            mst[cnt] = cur;
            cnt++;
            parent[d_prt] = s_prt;
        }
        i++;
    }
    display(mst,n);
}

int main() {
    int n,e,s,d,w;
    cout<<"Enter number of Vertices and Edges : ";
    cin>>n>>e;
    Edge edge_input[e];
    for(int i=0;i<e;i++) {
        cin>>s>>d>>w;
        Edge *ed = new Edge();
        ed->setData(s,d,w);
        edge_input[i] = *ed;
    }
    kruskal(edge_input,e,n);
    return 0;
}


