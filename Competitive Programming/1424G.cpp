#include<bits/stdc++.h>

/*

shinchanCoder Here!!

*/

using namespace std;

#define pb push_back
#define all(x) begin(x), end(x)

#define sz(x) (int)(x).size()

#define ff first
#define ss second

#define mp make_pair

#define ll long long
#define ld long double

#define mod 1000000007

int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll T,a,b;
    cin>>T;
    map<ll,ll> m;
    while(T--) {
        cin>>a>>b;
        m[a]++;
        m[b]--;
    }
    ll p=0,sum=0,y;
    for(auto& it : m) {
        sum+=it.ss;
        if(p<sum) {
            y=it.ff;
            p=sum;
        }
    }
    cout<<y<<" "<<p;
    return 0;
}


