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

#define mod 1000000007

int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin>>s;
    ll n = s.length();
    for(ll i=1;i<n;i++) {
        if(s[i]==s[i-1]) {
            if(i==n-1) {
                if(s[i]=='a')
                    s[i] = 'b';
                else
                    s[i] = 'a';
            }else {
                if(s[i+1]!='z') {
                    char ch = s[i+1]+1;
                    if(ch!=s[i]) {
                        s[i] = ch;
                    }else {
                        if(ch=='z') {
                            s[i] = 'a';
                        }else {
                            ch++;
                            s[i] = ch;
                        }
                    }
                }else {
                    if(s[i]=='y') {
                        s[i] = 'a';
                    }else {
                        s[i] = 'y';
                    }
                }
            }
        }
    }
    cout<<s;
    return 0;
}


