#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

int main() {
    vector<int> v[1001];
    int N,x;
    cin>>N;
    for(int i=2;i<=N;i++) {
        cin>>x;
        v[x].push_back(i);
    }
    for(int i=1;i<=N;i++) {
        if(!v[i].empty()) {
            int sum = 0;
            for(int y : v[i]) {
                if(v[y].empty()) {
                    sum++;
                }
            }
            if(sum<3) {
                cout<<"No";
                return 0;
            }
        }
    }
    cout<<"Yes";
    return 0;
}


