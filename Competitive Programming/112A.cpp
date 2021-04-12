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
    string s,s1;
    cin>>s>>s1;
    for(int i=0;i<s.length();i++) {
        s[i] = tolower(s[i]);
        s1[i] = tolower(s1[i]);
    }
    if(s==s1) {
        cout<<0;
    }else {
        if(s>s1) {
            cout<<1;
        }else {
            cout<<-1;
        }
    }
    return 0;
}


