#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

int main() {
    ll N;
    vector<int> v;
    vector<int>::iterator it;
    int x;
    cin>>N;
    for(int i=0;i<N;i++) {
        cin>>x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    it = unique(v.begin(),v.end());
    v.resize(distance(v.begin(),it));
    if(v.size()<2) {
        cout<<"NO";
        return 0;
    }
    cout<<v[1];
    return 0;
}


