#include<bits/stdc++.h>

/*

shinchanCoder Here!!

*/

using namespace std;

#define endll "\n"
#define pb push_back
#define all(x) begin(x), end(x)
#define allr(x) rbegin(x), rend(x)

#define sz(x) (int)(x).size()

#define ff first
#define ss second

#define mpr make_pair

#define len(x) x.length()

#define ll long long
#define ld long double
#define lli long long int

#define mod 1000000007

ll powmod(ll a,  ll b){
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

vector<ll> prm;

void Sieve(ll n) {
  bool prime[n+1];
  memset(prime,true, sizeof(prime));
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
    if(!a) {
        return b%mod;
    }
    return _gcd((b%a)%mod,a%mod);
}

ll nCr(ll n,ll r) {
    return (ld)fact(n)/(ld)(fact(r)*fact(n-r));
}

int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //Sieve(1000000);
    ll D,I,S,V,F,B,E,L,P,ind;
    string str_name;
    cin>>D>>I>>S>>V>>F;
    map<string,ll> st_ind;
    map<pair<ll,ll>,string> st_nm;
    vector<pair<ll,ll>> edg;
    ll intr[I][I];
    vector<vector<ll>> grp(I);
    memset(intr,0,sizeof(intr));
    for(ll i=0;i<S;i++) {
        cin>>B>>E>>str_name>>L;
        edg.pb(mpr(B,E));
        intr[B][E]=L;
        grp[E].pb(B);
        st_ind[str_name]=i;
        st_nm[mpr(B,E)]=str_name;
    }
    set<ll> stn;
    bool flag=false;
    while(V--) {
        cin>>P;
        string s;
        ll tm=0;
        ll sno=P;
        set<ll> st;
        while(P--) {
            cin>>s;
            st.insert(edg[st_ind[s]].ss);
            if(P!=sno-1) {
                ind=st_ind[s];
                tm+=intr[edg[ind].ff][edg[ind].ss];
            }
        }
        if(tm+sno/2<=D) {
            flag=true;
            for(auto& val : st) {
                stn.insert(val);
            }
        }
    }
    if(flag) {
        cout<<stn.size()<<endl;
        for(auto& val : stn) {
            cout<<val<<endl;
            cout<<grp[val].size()<<endl;
            for(auto& e : grp[val]) {
                cout<<st_nm[mpr(e,val)]<<" "<<1<<endl;
            }
        }
    }
    return  0;
}

