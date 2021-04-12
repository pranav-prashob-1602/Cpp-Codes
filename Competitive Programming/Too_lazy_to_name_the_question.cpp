//score 100

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
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll a,b,c;
    cin>>a>>b>>c;
    ll i=1,j=1,res=-1;
    while(c!=0) {
        ll x = a*i;
        ll y = b*j;
        if(x<y) {
            i++;
            res = x;
        }else if(x==y) {
            i++;
            j++;
            res = x;
        }else {
            j++;
            res = y;
        }
        c--;
    }
    ll z=-1;
    if(res%a==0) {
        z=a;
    }
    if(res%b==0) {
        if(z==-1) {
            z=b;
        }else {
            z = lcm(a,b);
        }
    }
    for(ll i=res;i>=0;i-=z) {
        cout<<i<<" ";
    }
    return 0;
}
