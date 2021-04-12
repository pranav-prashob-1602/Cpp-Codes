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
    ll n,d,x;
    string s;
    cin>>n>>d;
    cin>>s;
    ll i=0,j=1;
    bool flag = true;
    ll cnt=0;
    for(int i=0;i<n-1;i++) {
        j=0,x=-1;
        while(j<d && i+j+1<n) {
            if(s[i+j+1]=='1') {
                x=i+j;
            }
            j++;
        }
        if(x==-1 || x-i>=d) {
            flag = false;
            break;
        }else {
            i=x;
            cnt++;
        }
    }
    if(flag) {
        cout<<cnt;
    }else {
        cout<<-1;
    }
    return 0;
}


