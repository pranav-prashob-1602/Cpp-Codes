#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

int main() {
    ll T,n;//m,x1,x2,y1,y2;
    cin>>T;
    string s;
    while(T--) {
        cin>>n>>s;
        sort(s.begin(),s.end());
        cout<<s<<endl;
    }
    return 0;
}


