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
        cin>>n;
        if(n<10) {
            cout<<n<<endl;
        }else if(n>45){
            cout<<-1<<endl;
        }else {
            ll k = 9;
            string s = "";
            while(n!=0) {
                s+=('0'+k);
                n-=k;
                k = min(n,k-1);
            }
            reverse(s.begin(),s.end());
            cout<<s<<endl;
        }
    }
    return 0;
}


