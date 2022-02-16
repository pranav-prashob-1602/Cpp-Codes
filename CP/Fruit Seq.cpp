#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
 
int main()
{
    ll T,x,count = 0;
    string str;
    cin>>T;
    cin>>str;
    for(int i=0;i<T;i++) {
	count += x;
        x=0;
        for(int j=i;j<T;j++) {
            if(str[j] =='1') {
                x++;
            }else {
                if(x!=0) {
                 break;   
                }
            }
        }
    }
    cout<<count;
    return 0;
}