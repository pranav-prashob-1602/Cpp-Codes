#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

int main() {
    int n,m,T;
    cin>>T;
    while(T--) {
            cin>>n;
            int a[1000001] = {0};
            for(int i=0;i<n;i++) {
                cin>>m;
                a[m]++;
            }
            cout<<*max_element(a,a+1000001)<<endl;
    }
    return 0;
}


