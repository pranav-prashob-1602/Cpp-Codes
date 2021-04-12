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
    ll cnt = 0,cnt1 = 0;
    char ch;
    char a[8][8];
    for(int i=0;i<8;i++) {
        for(int j=0;j<8;j++) {
            cin>>a[i][j];
        }
    }
    for(int i=0;i<8;i++) {
        bool flag = true,flag1 = true;
        for(int j=0;j<8;j++) {
            flag&=(a[i][j]=='B');
            flag1&=(a[j][i]=='B');
        }
        cnt+=(flag==true);
        cnt1+=(flag1==true);
    }
    if(cnt==8) {
        cout<<cnt;
        return 0;
    }
    cout<<cnt+cnt1<<endl;
    return 0;
}


