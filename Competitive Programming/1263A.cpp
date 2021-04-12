#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

int main() {
    ll N,r,g,b,lar[3];
    cin>>N;
    while(N--) {
        for(int i=0;i<3;i++) {
            cin>>lar[i];
        }
        sort(lar,lar+3);
        if(lar[2]<=lar[0]+lar[1]) {
            cout<<(lar[0]+lar[1]+lar[2])/2<<endl;
        }else {
            cout<<lar[0]+lar[1]<<endl;
        }
    }
    return 0;
}


