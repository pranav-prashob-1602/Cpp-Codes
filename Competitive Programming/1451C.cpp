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
    ll T,n,k;
    string s1,s2;
    cin>>T;
    while(T--){
       cin>>n>>k;
       cin>>s1>>s2;
       vector<ll> a(27,0);
       vector<ll> b(27,0);
       for(auto& ch : s1) {
            a[ch-'a']++;
       }
       for(auto& ch : s2) {
            b[ch-'a']++;
       }
       ll i=0;
       for(i=0;i<26;i++) {
            if(a[i]<b[i] || (a[i]-b[i])%k!=0) {
                break;
            }
            a[i]-=b[i];
            a[i+1]+=a[i];
       }
       if(i!=26) {
            cout<<"NO"<<endl;
       }else {
            cout<<"YES"<<endl;
       }
    }
    return 0;
}


