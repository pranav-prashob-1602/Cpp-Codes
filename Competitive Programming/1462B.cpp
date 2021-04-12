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
    string str;
    cin>>T;
    while(T--) {
        cin>>n>>str;
        if(str[0]=='2' && str[1]=='0' && str[2]=='2' && str[3]=='0') {
            cout<<"Yes"<<endl;
        }else if(str[0]=='2' && str[1]=='0' && str[2]=='2' && str[n-1]=='0') {
            cout<<"Yes"<<endl;
        }else if(str[0]=='2' && str[1]=='0' && str[n-2]=='2' && str[n-1]=='0') {
            cout<<"Yes"<<endl;
        }else if(str[0]=='2' && str[n-3]=='0' && str[n-2]=='2' && str[n-1]=='0') {
            cout<<"Yes"<<endl;
        }else if(str[n-4]=='2' && str[n-3]=='0' && str[n-2]=='2' && str[n-1]=='0') {
            cout<<"Yes"<<endl;
        }else {
            cout<<"No"<<endl;
        }
    }
    return 0;
}


