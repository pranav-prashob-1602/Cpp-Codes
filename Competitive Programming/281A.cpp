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
    string s;
    cin>>s;
    if(!isupper(s[0])) {
        s[0]-=32;
    }
    cout<<s;
    return 0;
}


