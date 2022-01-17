#include<bits/stdc++.h>

using namespace std;

struct segtree {
    int sz;
    vector<long long> sums;

    void init(int n) {
        sz=1;
        while(sz<n) {
            sz*=2;
        }
        sums.assign(2*sz, 0LL);
    }

    void build(vector<int>& g, int x, int lx, int rx) {
        if(rx-lx==1) {
            if(lx<(int)g.size()) {
                sums[x]=g[lx];
            }
            return;
        }
        int m=(lx+rx)/2;
        build(g, 2*x+1, lx, m);
        build(g, 2*x+2, m, rx);
        sums[x]=sums[2*x+1]+sums[2*x+2];
    }

    void build(vector<int>& g) {
        build(g, 0, 0, sz);
    }

    void set(int i, int v, int x, int lx, int rx) {
        if(rx-lx==1) {
            sums[x]=v;
            return;
        }
        int m=(lx+rx)/2;
        if(i<m) {
            set(i, v, 2*x+1, lx, m);
        }else {
            set(i, v, 2*x+2, m, rx);
        }
        sums[x]=sums[2*x+1]+sums[2*x+2];
    }

    void set(int i, int v) {
        set(i, v, 0, 0, sz);
    }

    long long sum(int l, int r, int x, int lx, int rx) {
        if(rx<=l || r<=lx) {
            return 0;
        }
        if(lx>=l && rx<=r) {
            return sums[x];
        }
        int m=(lx+rx)/2;
        long long s1=sum(l, r, 2*x+1, lx, m);
        long long s2=sum(l, r, 2*x+2, m, rx);
        return s1+s2;
    }

    long long sum(int l, int r) {
        return sum(l, r, 0, 0, sz);
    }

};


int main() {
    int n, m, v, l, r, i, q;
    cin>>n>>m;

    segtree st;
    st.init(n);
    vector<int> g(n);
    for(int i=0;i<n;i++) {
        cin>>g[i];
    }
    st.build(g);
    while(m--) {
        cin>>q;
        if(q==1) {
            cin>>i>>v;
            st.set(i, v);
        }else {
            cin>>l>>r;
            cout<<st.sum(l, r)<<endl;
        }
    }
    return 0;
}
