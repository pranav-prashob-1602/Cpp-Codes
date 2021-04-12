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
#define lli long long int

#define mod 1000000007

int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    lli T,a,b,n,k,u,v;
    cin>>T;
    for(lli p=1;p<=T;p++) {
        cin>>a>>b>>n>>k;
        vector<ll> v1(k,0);
        vector<ll> v2(k,0);
        ll z,y,u,v;
        for(ll i=1;i<=k;i++) {
            z = pow(i,a);
            z%=k;
            u = pow(i,b);
            u%=k;
            y = ((n-i)/k)+1;
            v1[z]+=y;
            v2[u]+=y;
        }
        ll cnt = 0;
        for(ll i=0;i<k;i++) {
            cnt+=v1[i]*v2[(k-i)%k];
        }
        for(ll i=1;i<=k;i++) {
            z = pow(i,a)+pow(i,b);
            if(z%k==0) {
                cnt-=((n-i)/k)+1;
            }
        }
        cout<<"Case #"<<p<<": "<<cnt%mod<<endl;
    }
    return 0;
}


