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

/*
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll T,n,x;
    cin>>T;
    while(T--) {
        cin>>n;
        ll sum1=0,sum2=0;
        ll odd=0,even=0;
        vector<ll> od,ev;
        for(ll i=0;i<n;i++) {
            cin>>x;
            if(x%2) {
                od.pb(x);
                odd++;
            }else {
                ev.pb(x);
                even++;
            }
        }
        sort(all(od),greater<int> ());
        sort(all(ev),greater<int> ());
        bool flag = true;
        ll i=0,j=0;
        while((i+j)<n) {
            if(i==even) {
                if(flag) {
                    ++j;
                    flag = !flag;
                    continue;
                }
                sum1+=od[j];
                ++j;
            }else if(j==odd) {
                if(flag) {
                    sum2+=ev[i];
                    ++i;
                    flag = !flag;
                    continue;
                }
                ++i;
            }else {
                if(flag) {
                    if(ev[i]<=od[j]) {
                        ++j;
                    }else {
                        sum2+=ev[i];
                        ++i;
                    }
                }else {
                    if(ev[i]<od[j]) {
                        sum1+=od[j];
                        ++j;
                    }else {
                        ++i;
                    }
                }
            }
            flag = !flag;
        }
        if(sum1>sum2) {
            cout<<"Bob"<<endl;
        }else if(sum1==sum2) {
            cout<<"Tie"<<endl;
        }else {
            cout<<"Alice"<<endl;
        }
    }
    return 0;
}
*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll T,n,x;
    cin>>T;
    while(T--) {
        cin>>n;
        ll sum1=0,sum2=0;
        vector<ll> v;
        for(ll i=0;i<n;i++) {
            cin>>x;
            v.pb(x);
        }
        sort(all(v),greater<int> ());
        for(ll i=0;i<n;i++) {
            if(i%2 && v[i]%2) {
                sum1+=v[i];
            }
            if(i%2==0 && v[i]%2==0) {
                sum2+=v[i];
            }
        }
        if(sum1>sum2) {
            cout<<"Bob"<<endl;
        }else if(sum1==sum2) {
            cout<<"Tie"<<endl;
        }else {
            cout<<"Alice"<<endl;
        }
    }
    return 0;
}
