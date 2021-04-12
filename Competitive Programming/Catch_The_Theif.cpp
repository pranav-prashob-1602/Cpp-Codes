#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) begin(x), end(x)

#define sz(x) (int)(x).size()

#define f first
#define s second

#define mp make_pair

#define ll long long
#define ld long double

int main() {
    ll T,x,y,k,n,a,b,cnt;
    cin>>T;
    while(T--) {
        cin>>a>>b>>k>>n;
        x = max(a,b);
        y = min(a,b);
        if((x-y)%k==0 && ((x-y)/k)%2==0) {
            cout<<"Yes"<<endl;
        }else {
            cout<<"No"<<endl;
        }
    }
    return 0;
}


