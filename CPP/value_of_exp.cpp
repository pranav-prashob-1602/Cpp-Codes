#include<bits/stdc++.h>
#include<algorithm>
#include<unordered_map>
#include<vector>
#include<unordered_set>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<map>
#include<chrono>

/*

shinchanCoder Here!!

*/

using namespace std;
using namespace chrono;

#define debug(x) cout << #x << " " << x <<endl;
#define endll "\n"
#define pb push_back
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define all(x) begin(x), end(x)
#define allr(x) rbegin(x), rend(x)
#define forn(i,n) for(ll i=0;i<(n);i++)

#define sz(x) (ll)(x).size()
#define pr(x,y) pair<x,y>

#define ff first
#define ss second

#define mpr make_pair

#define len(x) x.length()

#define ll long long
#define ld long double
#define lli long long int

#define ull unsigned long long
#define uld unsigned long double
#define ulli unsigned long long int

#define mod 1000000007
#define PI 3.141592653589793238462

ll powmod(ll a, ll b){
    if(b==0){
        return 1 ;
    }
    ll x = powmod(a,b/2);
    x = (x*x)%mod ;
    if(b%2){
        x = (a*x)%mod ;
    }
    return x;
}

ll power(ll x, ll y) {
    ll res = 1;
    while (y > 0) {
        if (y & 1)
            res = res*x;
        y = y>>1;
        x = x*x;
    }
    return res;
}

vector<ll> prm;

void Sieve(ll n) {
    bool prime[n+1];
    memset(prime,true, sizeof(prime));
    prime[0]=false;
    prime[1]=false;
    for(ll p=2;p*p<=n;p++) {
        if(prime[p]==true) {
            for(ll i=p*p;i<=n;i+=p) {
                prime[i]=false;
            }
        }
    }
    if(!prm.empty()) {
        prm.clear();
    }
    for(ll p=2;p<=n;p++) {
        if(prime[p]) {
            prm.pb(p);
        }
    }
}

ll fact(ll n) {
    ll res = 1;
    for(ll i=2;i<=n;i++) {
        res*=i;
    }
    return res;
}

ll _lcm(ll x,ll y) {
    return x*y/__gcd(x,y);
}

ll _gcd(ll a,ll b) {
    return a%b==0 ? b : _gcd(b,a%b);
}

ll nCr(ll n,ll r) {
    return (ld)fact(n)/(ld)(fact(r)*fact(n-r));
}

void fun(vector<ld>& nums, vector<char>& ops, ll& n, ll& m, char op) {
    if(op=='*') {
        ll j=0;
        while(j<m) {
            if(ops[j]=='*') {
                nums[j]=(ld)nums[j]*nums[j+1];
                for(ll i=j+2;i<n;i++) {
                    nums[i-1]=nums[i];
                }
                for(ll i=j+1;i<m;i++) {
                    ops[i-1]=ops[i];
                }
                n--;
                m--;
            }else {
                j++;
            }
        }
    }else if(op=='/') {
        ll j=0;
        while(j<m) {
            if(ops[j]=='/') {
                nums[j]=(ld)nums[j]/nums[j+1];
                for(ll i=j+2;i<n;i++) {
                    nums[i-1]=nums[i];
                }
                for(ll i=j+1;i<m;i++) {
                    ops[i-1]=ops[i];
                }
                n--;
                m--;
            }else {
                j++;
            }
        }
    }else if(op=='+') {
        ll j=0;
        while(j<m) {
            if(ops[j]=='+') {
                nums[j]=(ld)nums[j]+(ld)nums[j+1];
                for(ll i=j+2;i<n;i++) {
                    nums[i-1]=nums[i];
                }
                for(ll i=j+1;i<m;i++) {
                    ops[i-1]=ops[i];
                }
                n--;
                m--;
            }else {
                j++;
            }
        }
    }else if(op=='-') {
        ll j=0;
        while(j<m) {
            if(ops[j]=='-') {
                nums[j]=(ld)nums[j]-nums[j+1];
                for(ll i=j+2;i<n;i++) {
                    nums[i-1]=nums[i];
                }
                for(ll i=j+1;i<m;i++) {
                    ops[i-1]=ops[i];
                }
                n--;
                m--;
            }else {
                j++;
            }
        }
    }
}

void solve() {
    ll T,n,x,k;
    cin>>T;
    while(T--) {
        string s;
        cin>>s;
        vector<char> ops;
        vector<ld> nums;
        for(auto& ch : s) {
            if(!(ch>='0' && ch<='9')) {
                ops.pb(ch);
                ch='?';
            }
        }
        ll i=0,j,temp;
        while(i<len(s)) {
            j=i,temp=0;
            while(s[j]!='?' && j<len(s)) {
                temp=temp*10+(s[j]-'0');
                j++;
            }
            nums.pb(temp);
            i=j+1;
        }
        ll n=nums.size();
        ll m=ops.size();
        fun(nums,ops,n,m,'/');
        fun(nums,ops,n,m,'*');
        fun(nums,ops,n,m,'+');
        fun(nums,ops,n,m,'-');
        cout<<nums[0]<<endll;
    }
}

int main() {
    fastio();
    solve();
    return 0;
}
