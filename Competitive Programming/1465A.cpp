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
    ll T,n;
    string s;
    cin>>T;
    while(T--) {
        cin>>n>>s;
        ll cnt = 0;
        for(int i=n-1;i>=0;i--) {
            if(s[i]!=')') {
                break;
            }else {
                cnt++;
            }
        }
        if(cnt>n-cnt) {
            cout<<"Yes"<<endl;
        }else {
            cout<<"No"<<endl;
        }
    }
    return 0;
}


