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
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n,res;
    cin>>n;
    res=0;
    set<ll> s;
    ll k=1;
    set<ll>:: iterator it;
    while(res!=n) {
        if(s.find(n-res)==s.end()) {
            res+=k;
            s.insert(k);
        }else {
            it = s.end();
            --it;
            s.erase(it);
            s.insert(n-(res-(k-1)));
            break;
        }
        k++;
    }
    cout<<s.size()<<endl;
    for(auto& val : s) {
        cout<<val<<" ";
    }
    return 0;
}



