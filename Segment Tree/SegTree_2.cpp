/*
**
**  Given an array arr of size N consisting of integers and Q queries.
**  Queries can be of two type:
**      1. x v, where x is the index and v is the new value, you need to update arr[x]=v.
**      2. l r, In the given range [l, r] of array arr, find the minimum element and count of the minimum element in the given range.
**
*/


#include<bits/stdc++.h>

using namespace std;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int n;
vector<int> v;

struct node {
    int mn, cnt;
    node(int mn=INT_MAX, int cnt=0) {
        this->mn = mn;
        this->cnt = cnt;
    }
};

node merge(node a, node b) {
    if(a.mn == b.mn) {
        return node(a.mn, a.cnt+b.cnt);
    }else if(a.mn < b.mn) {
        return a;
    }else {
        return b;
    }
}

vector<node> t;

void build(int ind, int l, int r) {
    if(l==r) {
        t[ind] = node(v[l], 1);
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
        t[ind] = node(val, 1);
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
            int x, v;
            cin>>x>>v;
            update(1, 0, n-1, x, v);
        }else {
            int l, r;
            cin>>l>>r;
            node p = query(1, 0, n-1, l, r);
            cout<<p.mn<<" "<<p.cnt<<endl;
        }
    }
}

int main() {
    fastio();

    shinchan();
    return 0;
}

/*
MY APPROACH

int n;
vector<int> v;

vector<pair<int, int>> t;


void build(int ind, int l, int r) {
    if(l==r) {
        t[ind] = {v[l], 1};
        return;
    }
    int mid = (l+r)/2;
    build(2*ind, l, mid);
    build(2*ind+1, mid+1, r);
    if(t[2*ind].first == t[2*ind+1].first) {
        t[ind] = {t[2*ind].first, t[2*ind].second+t[2*ind+1].second};
    }else if(t[2*ind].first < t[2*ind+1].first) {
        t[ind] = t[2*ind];
    }else {
        t[ind] = t[2*ind+1];
    }
}

void update(int ind, int l, int r, int pos, int val) {
    if(pos<l || pos>r) {
        return;
    }
    if(l==r) {
        t[ind] = {val, 1};
        v[l] = val;
        return;
    }
    int mid = (l+r)/2;
    update(2*ind, l, mid, pos, val);
    update(2*ind+1, mid+1, r, pos, val);
    if(t[2*ind].first == t[2*ind+1].first) {
        t[ind] = {t[2*ind].first, t[2*ind].second+t[2*ind+1].second};
    }else if(t[2*ind].first < t[2*ind+1].first) {
        t[ind] = t[2*ind];
    }else {
        t[ind] = t[2*ind+1];
    }
}

pair<int, int> query(int ind, int l, int r, int lq, int rq) {
    if(lq>r || l>rq) {
        return {INT_MAX, INT_MAX};
    }
    if(l>=lq && r<=rq) {
        return t[ind];
    }
    int mid = (l+r)/2;
    pair<int, int> a = query(2*ind, l, mid, lq, rq);
    pair<int, int> b = query(2*ind+1, mid+1, r, lq, rq);
    pair<int, int> res;
    if(a.first == b.first) {
        res = {a.first, a.second+b.second};
    }else if(a.first < b.first) {
        res = a;
    }else {
        res = b;
    }
    return res;
}

void shinchan() {
    int q, c;
    cin>>n;
    v = vector<int> (n);
    for(int i=0;i<n;i++) {
        cin>>v[i];
    }
    t = vector<pair<int, int>> (4*n);
    build(1, 0, n-1);
    cin>>q;
    while(q--) {
        cin>>c;
        if(c==1) {
            int x, v;
            cin>>x>>v;
            update(1, 0, n-1, x, v);
        }else {
            int l, r;
            cin>>l>>r;
            pair<int, int> p = query(1, 0, n-1, l, r);
            cout<<p.first<<" "<<p.second<<endl;
        }
    }
}

*/
