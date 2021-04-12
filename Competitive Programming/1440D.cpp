#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

int main() {
    ll T,n,k,x,m,a,b;
    cin>>T;
    while(T--) {
        cin>>n>>m>>k;
        map<ll,ll> mp;
        map<ll,ll> pnt;
        for(int i=0;i<m;i++) {
            cin>>a>>b;
            mp[a]++;
            mp[b]++;
            pnt.insert({a,b});
            pnt.insert({b,a});
        }
        vector<ll> v;
        for(auto& it : mp) {
            if(it.second == k) {
                v.push_back(it.first);
            }
        }
        if(v.size()<k) {
            for(auto& it : mp) {
                if(it.second==v.size()) {
                    bool flag = true;
                    for(auto& val : v) {

                    }
                }
            }
        }
        if(v.size()==0) {
            cout<<-1<<endl;
        }else {
            if(v.size() == k) {
                cout<<2<<endl;
            }else {
                cout<<1<<" "<<v.size()<<endl;
            }
            for(auto& val : v) {
                cout<<val<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}

