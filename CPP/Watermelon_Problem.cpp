#include<iostream>

using namespace std;

int main() {
        int n,i,x,flag=0;
        cin>>n;
        for(i=1;i<n;i++) {
            x = n-i;
            if(x%2 == 0 && i%2 == 0) {
                flag =1;
                break;
            }
        }
        if(flag)
            cout<<"YES";
        else
            cout<<"NO";
        return 0;
}
