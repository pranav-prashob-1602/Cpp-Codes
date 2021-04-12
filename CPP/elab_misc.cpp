#include<iostream>

using namespace std;

int main() {
    int i=0,a[100],n,j;
    while(cin>>n && cin.get() != 10) {
            a[i]=n;
            i=i+1;
    }
    a[i]=n;
    for(j=0;j<=i;j++) {
        cout<<a[j]<<"\n";
    }
    return 0;
}
