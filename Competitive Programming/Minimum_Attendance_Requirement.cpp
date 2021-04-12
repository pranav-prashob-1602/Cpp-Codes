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
        ll cnt = count(s.begin(),s.end(),'1');
        if(cnt+(120-n)>=90) {
            cout<<"YES"<<endl;
        }else {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}


