
#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

struct area {
    ld c,l;
};

bool cmp(const area& one,const area& two) {
    return one.c < two.c;
}

int main() {
    ll N,T;
    cin>>N>>T;
    area a[N];
    for(int i=0;i<N;i++) {
        cin>>a[i].c>>a[i].l;
    }
    sort(a,a+N,cmp);
    ld diff;
    ll res = 2;
    for(int i=0;i<N-1;i++) {
        diff = (ld) a[i+1].c - a[i+1].l/2.0 - a[i].c - a[i].l/2.0;
        if(diff>T) {
            res+=2;
        }else if(diff == T) {
            res++;
        }
    }
    cout<<res<<endl;
    return 0;
}


