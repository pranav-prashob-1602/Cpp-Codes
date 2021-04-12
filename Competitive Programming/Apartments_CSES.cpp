#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

int main() {
    ll T,n,m,k,x;
    vector<ll> a,p;
    vector<ll>::iterator up;
    cin>>n>>m>>k;
    for(int i=0;i<n;i++) {
        cin>>x;
        a.push_back(x);
    }
    sort(a.begin(),a.end());
    ll cnt = 0;
    for(int i=0;i<m;i++) {
        cin>>x;
        p.push_back(x);
    }
    sort(p.begin(),p.end());
    for(int i=0;i<m;i++) {
        x = p[i];
        up = upper_bound(a.begin(),a.end(),x-k-1);
        if(up != a.end()) {
            ll ind = up - a.begin();
            if(a[ind] <= x+k) {
                cnt++;
                a[ind] = -1;
            }
        }
        //cout<<x<<" "<<cnt<<endl;
    }
    cout<<cnt<<endl;
    return 0;
}


