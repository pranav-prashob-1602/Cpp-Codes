#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) begin(x), end(x)

#define sz(x) (int)(x).size()

#define ff first
#define ss second

#define mp make_pair

#define ll long long
#define ld long double

void print(map<ll,ll> p1,map<ll,ll> p2,int x) {
    cout<<x<<" ";
    if(p1[x]==0 && p2[x]==0) {
        return;
    }
    if(p1[x]!=0) {
        print(p1,p2,p1[x]);
    }else {
        print(p1,p2,p2[x]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n,x,y;
    vector<ll> v;
    map<ll,ll> p1,p2;
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>x;
        v.pb(x);
    }
    for(int i=0;i<n;i++) {
        auto it = find(v.begin(),v.end(),v[i]*2);
        if(it!=v.end()) {
            p1[v[i]] = v[i]*2;
        }
        if(v[i]%3==0) {
            auto it = find(v.begin(),v.end(),v[i]/3);
            if(it!=v.end()) {
                p2[v[i]] = v[i]/3;
            }
        }
    }
    if(p2.size()!=0) {
        x = p2.begin()->first;
        y = p2[x];
    }else {
        x = p1.begin()->first;
        y = p1[x];
    }
    cout<<x<<" ";
    print(p1,p2,y);
    /*for(auto& kv : p1) {
        cout<<kv.ff<<" "<<kv.ss<<"t";
    }
    cout<<endl;
    for(auto& kv : p2) {
        cout<<kv.ff<<" "<<kv.ss<<"t";
    }*/
    return 0;
}


