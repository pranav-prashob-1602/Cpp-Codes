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
    ll T;
    string str;
    cin>>T;
    while(T--) {
        cin>>str;
        ll cnt_0 = count(str.begin(),str.end(),'0');
        ll cnt_1 = str.length()-cnt_0;
        ll z = abs(cnt_0 - cnt_1);
        if(z%2==1) {
            cout<<-1<<endl;
        }else {
            z/=2;
            ll c = 0;
            if(z==0) {
                cout<<0<<endl;
            }else if(cnt_1 > cnt_0) {
                if(cnt_0) {
                    cout<<z<<endl;
                }else {
                    cout<<-1<<endl;
                }
            }else {
                if(cnt_1) {
                    cout<<z<<endl;
                }else {
                    cout<<-1<<endl;
                }
            }
        }
    }
    return 0;
}


