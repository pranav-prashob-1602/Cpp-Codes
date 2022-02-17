/*
**
**  Given an array arr of size N consisting of integers and Q queries.
**  Queries can be of two type:
**      1. l r v, In the given range [l, r] of array arr, add v to all the elements in the given range.
**      2. x, print the value of arr[x].
**
*/

#include<bits/stdc++.h>

using namespace std;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int n;
vector<int> v;

struct node {
    int val;
    node(int val=0) {
        this->val = val;
    }
};

node merge(node a, node b) {
    node t = node(a.val + b.val);
    return t;
}
vector<node> t;

void build(int ind, int l, int r) {
    if(l==r) {
        t[ind] = node(0);
        return;
    }
    int mid = (l+r)/2;
    build(2*ind, l, mid);
    build(2*ind+1, mid+1, r);
    t[ind] = merge(t[2*ind], t[2*ind+1]);
}

void update(int ind, int l, int r, int pos, int val) {
    if(pos<l || pos>r) {
        return;
    }
    if(l==r) {
        t[ind] = node(t[ind].val+val);
        return;
    }
    int mid = (l+r)/2;
    update(2*ind, l, mid, pos, val);
    update(2*ind+1, mid+1, r, pos, val);
    t[ind] = merge(t[2*ind], t[2*ind+1]);
}

node query(int ind, int l, int r, int lq, int rq) {
    if(lq>r || l>rq) {
        return node();
    }
    if(l>=lq && r<=rq) {
        return t[ind];
    }
    int mid = (l+r)/2;
    return merge(query(2*ind, l, mid, lq, rq), query(2*ind+1, mid+1, r, lq, rq));
}

void shinchan() {
    int q, c;
    cin>>n;
    v = vector<int> (n);
    for(int i=0;i<n;i++) {
        cin>>v[i];
    }
    t = vector<node> (4*n);
    build(1, 0, n-1);
    cin>>q;
    while(q--) {
        cin>>c;
        if(c==1) {
            int l, r, v;
            cin>>l>>r>>v;
            update(1, 0, n-1, l, v);
            if(r+1<n) {
                update(1, 0, n-1, r+1, -v);
            }
        }else {
            int x;
            cin>>x;
            node p = query(1, 0, n-1, 0, x);
            cout<<v[x]+p.val<<endl;
        }
    }
}

int main() {
    fastio();

    shinchan();
    return 0;
}
