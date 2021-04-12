  #include<bits/stdc++.h>

/*

shinchanCoder Here!!

*/

using namespace std;

#define endll "\n"
#define pb push_back
#define all(x) begin(x), end(x)
#define allr(x) rbegin(x), rend(x)
#define forn(i,n) for(ll i=0;i<(n);i++)

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


vector<int> ninjaChess2021(string k, string q) {
    int c,cm,st,sf,j,yq,xq,xk,yk;
    c=cm=st=sf=0;
    yq=q[0]-'a';
    xq=q[1]-'0'-1;
    yk=k[0]-'a';
    xk=k[1]-'0'-1;
    //int n=xk,m=yk,l=xq,o=yq;
    // cout<<xk<<" "<<yk<<endll;
    char ch[8][8];
    for(int i=0;i<8;i++) {
        for(int j=0;j<8;j++) {
            ch[i][j]='s';
        }
    }
    yq=q[0]-'a';
    xq=q[1]-'0'-1;
    yk=k[0]-'a';
    xk=k[1]-'0'-1;
    ch[xq][yq]='q';
    ch[xk][yk]='k';
    // cout<<xk<<" "<<yk<<endll;
    for(int i=xq+1;i<8;i++) {
        if(ch[i][yq]=='k')
            break;
        ch[i][yq]='c';
    }
    yq=q[0]-'a';
    xq=q[1]-'0'-1;
    yk=k[0]-'a';
    xk=k[1]-'0'-1;
    // cout<<xk<<" "<<yk<<endll;
   // cout<<xq<<endl;
    for(int i=xq-1;i>=0;i--) {
        if(ch[i][yq]=='k')
            break;
        ch[i][yq]='c';
    }
    yq=q[0]-'a';
    xq=q[1]-'0'-1;
    yk=k[0]-'a';
    xk=k[1]-'0'-1;
    // cout<<xk<<" "<<yk<<endll;
    for(int j=yq+1;j<8;j++) {
        if(ch[xq][j]=='k')
            break;
        ch[xq][j]='c';
    }
    yq=q[0]-'a';
    xq=q[1]-'0'-1;
    yk=k[0]-'a';
    xk=k[1]-'0'-1;
    // cout<<xk<<" "<<yk<<endll;
    for(int j=yq-1;j>=0;j--) {
        if(ch[xq][j]=='k')
            break;
        ch[xq][j]='c';
    }
    yq=q[0]-'a';
    xq=q[1]-'0'-1;
    yk=k[0]-'a';
    xk=k[1]-'0'-1;
    // cout<<xk<<" "<<yk<<endll;
    j=yq+1;
    for(int i=xq+1;i<8,j<8;i++,j++) {
        if(ch[i][j]=='k') {
            break;
        }
        ch[i][j]='c';
    }
    yq=q[0]-'a';
    xq=q[1]-'0'-1;
    yk=k[0]-'a';
    xk=k[1]-'0'-1;
    // cout<<xk<<" "<<yk<<endll;
    j=yq-1;
    for(int i=xq+1;i<8,j>=0;i++,j--) {
        if(ch[i][j]=='k') {
            break;
        }
        ch[i][j]='c';
    }
    yq=q[0]-'a';
    xq=q[1]-'0'-1;
    yk=k[0]-'a';
    xk=k[1]-'0'-1;
    // cout<<xk<<" "<<yk<<endll;
    j=yq-1;
    for(int i=xq-1;i>=0,j>=0;i--,j--) {
        if(ch[i][j]=='k') {
            break;
        }
        ch[i][j]='c';
    }
    yq=q[0]-'a';
    xq=q[1]-'0'-1;
    yk=k[0]-'a';
    xk=k[1]-'0'-1;
    // cout<<xk<<" "<<yk<<endll;
    j=yq+1;
    for(int i=xq-1;i>=0,j<8;i--,j++) {
        if(ch[i][j]=='k') {
            break;
        }
        ch[i][j]='c';
    }
    yq=q[0]-'a';
    xq=q[1]-'0'-1;
    yk=k[0]-'a';
    xk=k[1]-'0'-1;
    // cout<<xk<<" "<<yk<<endll;
    for(int i=0;i<8;i++) {
        for(int j=0;j<8;j++) {
            if((abs(i-xq)<=2 && abs(j-yq)<=2) && (ch[i][j]!='q' && ch[i][j]!='k')) {
                ch[i][j]='c';
            }
        }
    }
    yq=q[0]-'a';
    xq=q[1]-'0'-1;
    yk=k[0]-'a';
    xk=k[1]-'0'-1;
    // cout<<xk<<" "<<yk<<endll;
    //cout<<xk<<" "<<yk<<endll;
    for(int i=0;i<8;i++) {
        //cout<<0;
        for(int j=0;j<8;j++) {
                //cout<<1;
            if((abs(xk-i)<=1 && abs(yk-j)<=1)  && ch[i][j]!='k' && ch[i][j]!='q') {
                //cout<<0;
                ch[i][j]='e';
            }
        }
    }
    yq=q[0]-'a';
    xq=q[1]-'0'-1;
    yk=k[0]-'a';
    xk=k[1]-'0'-1;
    int cnt=0;
    if(abs(xq-xk)<=1 && abs(yq-yk)<=1) {
        for(int i=0;i<8;i++) {
            for(int j=0;j<8;j++) {
                if(ch[i][j]=='c') {
                    if(!((i+1<8 && ch[i+1][j]=='s') ||
                        (i+1<8 && j+1<8 && ch[i+1][j+1]=='s') ||
                        (j+1<8 && ch[i][j+1]=='s') ||
                        (i-1>-1 && ch[i-1][j]=='s') ||
                        (j-1>-1 && i-1>-1 && ch[i-1][j-1]=='s') ||
                        (j-1>-1 && ch[i][j-1]=='s') ||
                        (i+1<8 && j-1>-1 && ch[i+1][j-1]=='s') ||
                        (i-1>-1 && j+1<8 && ch[i-1][j+1]=='s'))) {
                        ch[i][j]='M';
                    }
                }
            }
        }
    }else {
        for(int i=0;i<8;i++) {
            for(int j=0;j<8;j++) {
                if(ch[i][j]=='c' && abs(i-xq)>1 && abs(j-yq)>1) {
                    if(!((i+1<8 && ch[i+1][j]=='s') ||
                        (i+1<8 && j+1<8 && ch[i+1][j+1]=='s') ||
                        (j+1<8 && ch[i][j+1]=='s') ||
                        (i-1>-1 && ch[i-1][j]=='s') ||
                        (j-1>-1 && i-1>-1 && ch[i-1][j-1]=='s') ||
                        (j-1>-1 && ch[i][j-1]=='s') ||
                        (i+1<8 && j-1>-1 && ch[i+1][j-1]=='s') ||
                        (i-1>-1 && j+1<8 && ch[i-1][j+1]=='s'))) {
                        ch[i][j]='M';
                    }
                }
            }
        }
    }
    for(int i=0;i<8;i++) {
        for(int j=0;j<8;j++) {
            if(ch[i][j]=='s') {
                if(!((i+1<8 && ch[i+1][j]=='s') ||
                    (i+1<8 && j+1<8 && ch[i+1][j+1]=='s') ||
                    (j+1<8 && ch[i][j+1]=='s') ||
                    (i-1>-1 && ch[i-1][j]=='s') ||
                    (j-1>-1 && i-1>-1 && ch[i-1][j-1]=='s') ||
                    (j-1>-1 && ch[i][j-1]=='s') ||
                    (i+1<8 && j-1>-1 && ch[i+1][j-1]=='s') ||
                    (i-1>-1 && j+1<8 && ch[i-1][j+1]=='s'))) {
                    ch[i][j]='F';
                }
            }
        }
    }
    yq=q[0]-'a';
    xq=q[1]-'0'-1;
    yk=k[0]-'a';
    xk=k[1]-'0'-1;
    c=cm=st=sf=0;
    for(int i=0;i<8;i++) {
        for(int j=0;j<8;j++) {
            cout<<ch[i][j]<<" ";
        }
        cout<<"\n";
    }
    for(int i=0;i<8;i++) {
        for(int j=0;j<8;j++) {
            if(ch[i][j]=='s') {
                sf++;
            }else if(ch[i][j]=='c') {
                c++;
            }else if(ch[i][j]=='M') {
                cm++;
            }else if(ch[i][j]=='F') {
                st++;
            }
        }
    }
    vector<int> res;
    res.push_back(cm);
    res.push_back(c);
    res.push_back(st);
    res.push_back(sf);
    return res;
}

int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //Sieve(1000000);
    vector<int> v;
    v=ninjaChess2021("b2","d4");
    for(auto& val : v) {
        cout<<val<<" ";
    }
    return 0;
}
