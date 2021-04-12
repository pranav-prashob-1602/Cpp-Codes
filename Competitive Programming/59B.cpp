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

int main() {
    ll n,even=0,sum=0,min_odd=INT_MAX,x;
    vector<ll> odd;
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>x;
        if(x%2) {
            odd.pb(x);
            sum+=x;
            min_odd = min(min_odd,x);
        }else {
            even+=x;
        }
    }
    if(odd.size()==0) {
        cout<<0<<endl;
    }else if(odd.size()%2) {
        cout<<sum+even<<endl;
    }else {
        cout<<sum+even-min_odd<<endl;
    }
    return 0;
}


