#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

int main() {
    ll T,N,W;
    cin>>T;
    while(T--) {
        cin>>N>>W;
        pair<ll,ll> A[200001];
        for(int i=1;i<=N;i++) {
            cin>>A[i].first;
            A[i].second = i;
        }
        sort(A+1,A+N+1);
        ll sum = 0;
        vector<ll> ind;
        for(int i = N;i>=1;i--) {
            if(sum+A[i].first>W) {
                continue;
            }
            sum+=A[i].first;
            ind.push_back(A[i].second);
        }
        if(sum<(W+1)/2) {
            cout<<-1<<endl;
            continue;
        }
        cout<<ind.size()<<endl;
        for(auto& val: ind) {
            cout<<val<<" ";
        }
        cout<<endl;
    }
    return 0;
}
