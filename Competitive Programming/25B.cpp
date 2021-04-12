#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

int main() {
    ll N;
    string s;
    cin>>N>>s;
    for(int i=0;i<N;i++) {
        cout<<s[i];
        if(i%2==1 && i+2<N) {
            cout<<"-";
        }
    }
    return 0;
}


