/*
**
**  Given an array arr of size N consisting of integers and Q queries.
**  Queries can be of two type:
**      1. l r v, In the given range [l, r] of array arr, add v to all the elements in the given range.
**      2. x, print the value of arr[x].
**
*/

/*
4
1 2 3 4
11
1 0 2 1
1 1 3 2
2 0
2 1
2 2
2 3
1 2 3 3
2 0
2 1
2 2
2 3
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
        t[ind] = node(v[l]);
        return;
    }
    int mid = (l+r)/2;
    build(2*ind, l, mid);
    build(2*ind+1, mid+1, r);
//    t[ind] = merge(t[2*ind], t[2*ind+1]);
}

void update(int ind, int l, int r, int lq, int rq, int val) {
    if(lq>r || l>rq) {
        return;
    }
    if(l>=lq && r<=rq) {
        t[ind] = node(t[ind].val + val);
        return;
    }
    int mid = (l+r)/2;
    update(2*ind, l, mid, lq, rq, val);
    update(2*ind+1, mid+1, r, lq, rq, val);
//    t[ind] = merge(t[2*ind], t[2*ind+1]);
}

node query(int ind, int l, int r, int x) {
    if(l==r) {
        if(x==l) {
            return t[ind];
        }else {
            return node();
        }
    }
    if(l<=x && x<=r) {
//        cout<<l<<" "<<r<<endl;
        int mid = (l+r)/2;
        node temp =  merge(query(2*ind, l, mid, x), query(2*ind+1, mid+1, r, x));
        return merge(temp, t[ind]);
    }else {
        return node();
    }
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
            update(1, 0, n-1, l, r, v);
        }else {
            int x;
            cin>>x;
            node p = query(1, 0, n-1, x);
            cout<<p.val<<endl;
        }
    }
}

int main() {
    fastio();

    shinchan();
    return 0;
}

