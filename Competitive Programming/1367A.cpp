#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

int main() {
    ll T,n,x;
    string s;
    cin>>T;
    while(T--) {
        cin>>s;
        string s1;
        s1+=s[0];
        for(int i=1;i<s.length();i+=2) {
            s1+=s[i];
        }
        cout<<s1<<endl;
    }
    return 0;
}


