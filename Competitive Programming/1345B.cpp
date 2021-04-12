/*#include<bits/stdc++.h>

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
    ll T,n;
    cin>>T;
    while(T--) {
        cin>>n;
        ll cnt=0,k,l;
        while(n>1) {
            k=2;
            l=2;
            while(k+l*2+l-1<=n) {
                k+=l*2+l-1;
                l++;
            }
            n-=k;
            cnt++;
        }
        cout<<cnt<<endl;
    }
    return 0;
}*/


// DP SOLUTION

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

ll pyd[100005] = {0};

ll bsearch(ll x) {
    ll s=0,e=100000;
    while(s<e) {
        ll mid = (s+e)/2;
        if(pyd[mid]>x) {
            e = mid-1;
        }else {
            s = mid;
        }
    }
    return pyd[s];
}

void init() {
    pyd[1] = 2;
    for(ll i=2;i<100000;i++) {
        pyd[i] = pyd[i-1]*3-1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    ll T,n;
    cin>>T;
    while(T--) {
        cin>>n;
        ll cnt=0;
        while(1) {
            ll z = bsearch(n);
            if(z==0) {
                break;
            }
            n-=z;
            cnt++;
        }
        cout<<cnt<<endl;
    }
    return 0;
}



