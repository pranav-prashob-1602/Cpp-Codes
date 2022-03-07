/*
**
**  Given an array arr of size N consisting of integers and Q queries.
**  Queries can be of two type:
**      1. x v, where x is the index and v is the new value, you need to update arr[x]=v.
**      2. l r, In the given range [l, r] of array arr, find the maximum sum sub-array.
**
*/


#include<bits/stdc++.h>

using namespace std;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int n;
vector<int> v;

struct node {
    int val, lval, rval, totval;

    node(int lval=INT_MIN, int val=INT_MIN, int rval=INT_MIN, int totval=INT_MIN) {
        this->val = val;
        this->lval = lval;
        this->rval = rval;
        this->totval = totval;
    }

};

node merge(node a, node b) {
    node temp = node();
    temp.val = max({a.val, b.val, a.rval + b.lval});
    temp.rval = max({a.rval + b.totval, a.rval});
    temp.lval = max({b.lval + a.totval, a.lval});
    temp.totval = a.totval + b.totval;
    return temp;
}

vector<node> t;

void build(int ind, int l, int r) {
    if(l==r) {
        t[ind]=node(0, v[l], 0, v[l]);
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
        t[ind] = node(0, val, 0, val);
        v[l] = val;
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
            int x, val;
            cin>>x>>val;
            update(1, 0, n-1, x, val);
        }else {
            int l, r;
            cin>>l>>r;
            node p = query(1, 0, n-1, l, r);
            cout<<p.val<<endl;
        }
    }
}

int main() {
    fastio();

    shinchan();
    return 0;
}
