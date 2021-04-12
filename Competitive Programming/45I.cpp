#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) begin(x), end(x)

#define sz(x) (int)(x).size()

#define ff first
#define ss second

#define mp make_pair

#define ll long long
#define ld long double

int main() {
    ll m,x;
    vector<ll> v;
    cin>>m;
    ll n=0;
    for(ll i=0;i<m;i++) {
        cin>>x;
        v.pb(x);
    }
    if(m==1) {
        cout<<v[0]<<endl;
        return 0;
    }
    sort(v.begin(),v.end());
    for(ll i=0;i<m;i++) {
        if(v[i]>0) {
            cout<<v[i]<<" ";
            n+=1;
        }else if(v[i]<0 && v[i+1]<0) {
            cout<<v[i]<<" "<<v[i+1]<<" ";
            n+=1;
            i++;
        }
    }
    if(!n) {
        cout<<n<<" ";
    }
    return 0;
}


