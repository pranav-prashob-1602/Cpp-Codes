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
    ll N,T,len,res,x;
    string s;
    cin>>T;
    while(T--) {
        cin>>s;
        string temp = s;
        len = s.length();
        N = stoi(s);
        res = N;
        for(int i=0;i<len;i++) {
            temp.erase(temp.begin()+i);
            x = stoi(temp);
            res = min(res,x);
            temp = s;
        }
        cout<<res<<endl;
    }
    return 0;
}


