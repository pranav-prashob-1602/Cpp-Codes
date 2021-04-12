#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

int main() {
    ll T,n,k;
    cin>>T;
    while(T--) {
        cin>>n>>k;
        ll a,b;
        vector<pair<ll,ll>> v;
        for(int i=0;i<n;i++) {
            cin>>a>>b;
            v.push_back(make_pair(a,b));
        }
        bool flag = true,flag1 = false;
        for(int i=0;i<n;i++) {
            flag = true;
            for(int j=0;j<n;j++) {
                if(i!=j) {
                    ll z = abs(v[i].first - v[j].first) + abs(v[i].second - v[j].second);
                    flag&=(z<=k);
                }
            }
            if(flag) {
                flag1=true;
                break;
            }
        }
        if(flag1) {
            cout<<1<<endl;
        }else {
            cout<<-1<<endl;
        }
    }
    return 0;
}


