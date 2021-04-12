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
    ll T;
    string s1,s2,s3;
    bool flag = true;
    cin>>T;
    while(T--) {
        cin>>s1>>s2>>s3;
        flag = true;
        for(ll i=0;i<s1.length();i++ ){
            flag&=(s1[i]==s3[i] || s2[i]==s3[i]);
        }
        if(flag) {
            cout<<"YES"<<endl;
        }else {
            cout<<"NO"<<endl;
        }
     }
    return 0;
}


