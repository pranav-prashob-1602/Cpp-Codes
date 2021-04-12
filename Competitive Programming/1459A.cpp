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
    ll T,n,x,y,p,q;
    cin>>T;
    while(T--) {
        string r,b;
        cin>>n>>r>>b;
        x=0,y=0;
        for(ll i=0;i<n;i++) {
            p = r[i]-'0';
            q = b[i]-'0';
            if(p>q) {
                x++;
            }else if(p<q) {
                y++;
            }
        }
        if(x>y) {
            cout<<"RED"<<endl;
        }else if(x==y) {
            cout<<"EQUAL"<<endl;
        }else {
            cout<<"BLUE"<<endl;
        }
    }
    return 0;
}


