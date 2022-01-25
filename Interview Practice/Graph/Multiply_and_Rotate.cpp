#include<bits/stdc++.h>

#define ll long long int

using namespace std;

int main() {
    ll n,k;
    cin>>n>>k;
    queue<ll> q;
    vector<ll> v(10000001, -1);
    q.push(1);
    v[1]=0;
    while(!q.empty()) {
        ll p = q.front();
        q.pop();
        if(p*n<=v.size() && v[p*n]==-1) {
            q.push(p*n);
            v[p*n]=1+v[p];
        }
        if(p>=10 && p%10!=0) {
            ll b=1,t;
            while(b<=p){
                b*=10;
            }
            t=(p%10*b+p)/10;
            if(v[t]==-1) {
                q.push(t);
                v[t]=v[p]+1;
            }
        }
    }
    cout<<v[k];
    return 0;
}
