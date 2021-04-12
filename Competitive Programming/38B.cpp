#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

int main() {
    int x1,y1,x2,y2;
    char a,b;
    cin>>a>>y1;
    x1 = a - 'a';
    cin>>b>>y2;
    x2 = b - 'a';
    y1-=1;
    y2-=1;
    int cnt = 0;
    for(int i=0;i<8;i++) {
        for(int j=0;j<8;j++) {
            if(!((i==x1 || j==y1) || (i==x2 && j==y2) || (abs((i-x1)*(j-y1))==2 || abs((i-x2)*(j-y2))==2))) {
                cnt++;
            }
        }
    }
    cout<<cnt;
    return 0;
}
