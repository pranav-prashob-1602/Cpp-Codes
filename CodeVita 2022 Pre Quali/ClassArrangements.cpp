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

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

#define endll "\n"
#define pb push_back
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define all(x) begin(x), end(x)
#define allr(x) rbegin(x), rend(x)

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

void _google(ll f) {cout<<"Case #"<<f<<": ";}


#define md 998244353

void shinchan() {
    vector<vector<ll>> v(10, vector<ll> (10));
    vector<vector<string>> g(10, vector<string> (10));
    string s;
    for(ll i=9;i>=0;i--) {
        for(ll j=0;j<10;j++) {
            cin>>s;
            g[i][j]=s;
            if(s=="Start") {
                v[i][j]=1;
                continue;
            }
            if(s=="End") {
                v[i][j]=100;
                continue;
            }
            if(s[0]=='L' || s[0]=='S') {
                string t="";
                ll k=2;
                while(k<(ll)len(s) && s[k]!=')') {
                    t+=s[k];
                    k++;
                }
                if(t=="Start") {
                    t="1";
                }
                if(t=="End") {
                    t="100";
                }
//                cout<<t<<" ";
                v[i][j]=stoll(t);
//                cout<<v[i][j]<<endll;
            }else {
                v[i][j]=stoll(s);
//                cout<<s<<endll;
            }
        }
        if(i%2) {
            reverse(all(v[i]));
            reverse(all(g[i]));
        }
    }
    ll n=10;
//    for(ll i=0;i<n;i++) {
//        for(ll j=0;j<n;j++) {
//            cout<<v[i][j]<<" ";
//        }
//        cout<<endll;
//    }
    ll sn=0,lad=0;
    getline(cin, s);
//    cout<<s<<endll;
    getline(cin, s);
    ll i=0,j=0,k;
    bool flag=false;
    ll t=1;
    i=(t-1)/10;
    j=(t-1)%10;
    flag|=v[i][j]==100;
    map<pr(ll,ll), bool> mp1;
    while(v[i][j]!=i*10+j+1) {
        if(mp1[{i, j}]==true) {
            flag=false;
            goto end;
        }
        mp1[{i, j}]=true;
        if(g[i][j][0]=='S' && g[i][j][1]=='(') {
            sn++;
        }else if(g[i][j][0]=='L' && g[i][j][1]=='(') {
            lad++;
        }
//        cout<<g[i][j]<<" ";
        ll q=v[i][j];
        i=q/10;
        j=(10+q%10-1)%10;
//        cout<<i<<" "<<j<<" "<<v[i][j]<<endll;
    }
//    cout<<g[i][j]<<" "<<i<<" "<<j<<" "<<v[i][j]<<endll;
    if(flag) {
        goto end;
    }
    for(ll p=0;p<(ll)len(s);p+=2) {
//        cout<<k<<endll;
//        break;
        k = s[p]-'0';
        t=v[i][j];
        flag|=(v[i][j]==100);
        if(t+k>100) {
            continue;
        }
        t+=k;
        t-=1;
        i=t/10;
        j=t%10;
        map<pr(ll,ll), bool> mp;
        while(v[i][j]!=i*10+j+1) {
            if(mp[{i, j}]==true) {
                flag=false;
                goto end;
            }
            mp[{i, j}]=true;
            if(g[i][j][0]=='S' && g[i][j][1]=='(') {
                sn++;
            }else if(g[i][j][0]=='L' && g[i][j][1]=='(') {
                lad++;
            }
//            cout<<g[i][j]<<" ";
            ll q=v[i][j];
            i=q/10;
            j=(10+q%10-1)%10;
//            cout<<i<<" "<<j<<" "<<v[i][j]<<endll;
        }
//        cout<<g[i][j]<<" "<<i<<" "<<j<<" "<<v[i][j]<<endll;
    }
    flag|=(v[i][j]==100);
    end:
        if(flag) {
            cout<<"Possible "<<sn+1<<" "<<lad+1<<endll;
        }else {
            cout<<"Not possible "<<sn<<" "<<lad<<" "<<v[i][j]-1<<endll;
        }


}

int main() {
    fastio();
    shinchan();
    return 0;
}
