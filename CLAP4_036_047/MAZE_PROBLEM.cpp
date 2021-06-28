#include<bits/stdc++.h>


/*

shinchanCoder Here!!

*/

using namespace std;

#define debug(x) cout << #x << " " << x <<endl;
#define endll "\n"
#define pb push_back

#define pr(x,y) pair<x,y>

#define ff first
#define ss second

#define mpr make_pair

#define ll long long
#define pp pr(ll,pr(ll,ll))



const ll inf=1e9;
bool vis[1001][1001];
ll adj[1001][1001];
ll wgt[1001][1001];
ll dist[1001][1001];


ll dir[] = {-1, 0, 1, 0, -1};

bool isSafe(ll r, ll c, ll n, ll m) {
    if(r<=0 || r>n || c<=0 || c>m || vis[r][c] || adj[r][c]) {
        return false;
    }else {
        return true;
    }
}

void dijkstra(ll x, ll y, ll n, ll m) {
    priority_queue<pp, vector<pp>, greater<pp>> pq;
    pq.push(mpr(wgt[n][1],mpr(x ,y)));
    vis[x][y]=true;
    dist[x][y]=wgt[x][y];
    while(!pq.empty()) {
        pp p=pq.top();
        ll d=p.ff;
        ll r=p.ss.ff;
        ll c=p.ss.ss;
        pq.pop();
        for(ll i=0;i<4;i++) {
            if(isSafe(r+dir[i],c+dir[i+1],n,m) && d+wgt[r+dir[i]][c+dir[i+1]]<dist[r+dir[i]][c+dir[i+1]]) {
                ll rr=r+dir[i];
                ll cc=c+dir[i+1];
                vis[rr][cc]=true;
                dist[rr][cc]=dist[r][c]+wgt[rr][cc];
                pq.push(mpr(dist[rr][cc],mpr(rr,cc)));
            }
        }
    }
}

void solve() {
    ll n,m,x,y;
    cout<<"INPUT THE DIMENSIONS :";
    cin>>n>>m;
    cout<<endl;
    cout<<"INPUT THE MAZE :"<<endl;
    for(ll i=1;i<=n;i++) {
        for(ll j=1;j<=m;j++) {
            cin>>adj[i][j];
        }
    }
    cout<<"INPUT THE COST :"<<endl;
    for(ll i=1;i<=n;i++) {
        for(ll j=1;j<=m;j++) {
            cin>>wgt[i][j];
        }
    }
    for(ll i=1;i<=n;i++) {
        for(ll j=1;j<=m;j++) {
            dist[i][j]=inf;
            if(adj[i][j]) {
                wgt[i][j]=inf;
            }
        }
    }
    ll r1=n,c1=1; // Start Points
    dijkstra(r1,c1,n,m);
    ll r2=1,c2=m; // End Points
    if(dist[r2][c2]==inf) {
        cout<<"THERE'S NO PATH FROM (N,1) to (1,M)"<<endll;
    }else {
        cout<<"Minimum Cost to reach the Top Left position is : ";
        cout<<dist[r2][c2]<<endll;
    }
}

int main() {
    solve();
    return 0;
}
