/*
**
**  Given an array arr of size N consisting of integers and Q queries.
**  Queries can be of two type:
**      1. x v, where x is the index and v is the new value, you need to update arr[x]=v.
**      2. l r, find the sum of range [l, r] of array arr.
**
*/


#include<bits/stdc++.h>

using namespace std;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int n;
vector<int> v;

vector<int> t;

void build(int ind, int l, int r) {
    if(l == r) {
        t[ind] = v[l];
        return;
    }
    int mid = (l+r)/2;
    build(ind*2, l, mid);
    build(ind*2+1, mid+1, r);
    t[ind] = t[2*ind]+t[2*ind+1];
}

void update(int ind, int l, int r, int pos, int val) {
    if(pos<l || pos>r) {
        return;
    }
    if(l==r) {
        t[ind] = val;
        v[l] = val;
        return;
    }
    int mid = (l+r)/2;
    update(ind*2, l, mid, pos, val);
    update(ind*2+1, mid+1, r, pos, val);
    t[ind] = t[2*ind]+t[2*ind+1];
}

int query(int ind, int l, int r, int lq, int rq) {
    if(l>rq || lq>r) {
        return 0;
    }
    if(lq<=l && r<=rq) {
        return t[ind];
    }
    int mid = (l+r)/2;
    return query(2*ind, l, mid, lq, rq)+query(2*ind+1, mid+1, r, lq, rq);
}

void shinchan() {
    int q, c;
    cin>>n;
    v = vector<int> (n);
    for(int i=0;i<n;i++) {
        cin>>v[i];
    }
    t = vector<int> (4*n);
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
            cout<<query(1, 0, n-1, l, r)<<endl;
        }
    }
}

int main() {
    fastio();

    shinchan();
    return 0;
}
