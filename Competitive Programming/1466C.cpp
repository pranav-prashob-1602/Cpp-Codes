#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) begin(x), end(x)

#define sz(x) (int)(x).size()

#define ff first
#define ss second

#define mp make_pair

#define ll long long
#define ld long double

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll T,n,x;
    cin>>T;
    string s;
    while(T--) {
        cin>>s;
        ll cnt = 0;
        for(ll i=0;i<s.length()-1;i++) {
            if(s[i]>='a' && s[i]<='z') {
                if(i<s.length()-2 && s[i]==s[i+2]) {
                    if(s[i]!=s[i+1]) {
                        s[i+2] = '$';
                        cnt++;
                    }else {
                        s[i+1] ='$';
                        s[i+2] = '*';
                        cnt+=2;
                    }
                }else if(i<s.length()-1 && s[i]==s[i+1]) {
                    s[i+1] = '$';
                    cnt++;
                }
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}


