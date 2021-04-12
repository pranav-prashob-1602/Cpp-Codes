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
    ll T,n,k,l,r;
    cin>>T;
    while(T--) {
        cin>>n>>k;
        if(n>k) {
            cout<<-1<<endl;
            continue;
        }
        string s = "";
        while(n>0) {
            s+='a'+ceil(log2((k+n-1)/n));
            if(ceil(log2((k+n-1)/n))>25) {
                break;
            }
            k-=pow(2,ceil(log2((k+n-1)/n)));
            n--;
        }
        if(k!=0) {
            cout<<-1<<endl;
        }else {
            cout<<s<<endl;
        }
    }
    return 0;
}


