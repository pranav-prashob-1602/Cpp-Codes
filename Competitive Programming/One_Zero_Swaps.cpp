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
    cin>>T;
    while(T--) {
        string s1,s2;
        cin>>n>>s1>>s2;
        ll cnt = 0,one=0,zero=0;
        bool flag = true;
        for(int i=0;i<n;i++) {
            if(s1[i]!=s2[i]) {
                if(s1[i]=='0') {
                    flag = false;
                    break;
                }
                s1[i] = '0';
                i++;
                while(s1[i]==s2[i] && i<n) {
                    i++;
                }
                if(i==n) {
                    flag = false;
                    break;
                }else {
                    if(s1[i]=='1') {
                        flag = false;
                        break;
                    }
                }
                s1[i] ='1';
            }
        }
        if(flag) {
            cout<<"Yes"<<endl;
        }else {
            cout<<"No"<<endl;
        }
    }
    return 0;
}


