#include<bits/stdc++.h>

/*

shinchanCoder Here!!

*/

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
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin>>s;
    bool flag = true;
    ll x;
    ll n =s.length();
    for(ll i=0;i<n;) {
        if(s[i]=='1') {
            i++;
            if(s[i]=='4') {
                i++;
                if(s[i]=='4') {
                    i++;
                }
            }
        }else {
            flag = false;
            break;
        }
    }
    if(flag) {
        cout<<"YES"<<endl;
    }else {
        cout<<"NO"<<endl;
    }
    return 0;
}

