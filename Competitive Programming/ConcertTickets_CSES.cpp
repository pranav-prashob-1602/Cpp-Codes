#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

int main() {
    ll n,m,x,cnt;
    multiset<ll,greater<int>> ms;
    cin>>n>>m;
    for(int i=0;i<n;i++) {
        cin>>x;
        ms.insert(x);
    }
    for(int i=0;i<m;i++) {
        cin>>x;
        auto it = ms.lower_bound(x);
        if(it==ms.end()) {
            cout<<-1<<endl;
            continue;
        }else {
            cout<<*it<<endl;
            ms.erase(it);
        }
    }
    return 0;
}


