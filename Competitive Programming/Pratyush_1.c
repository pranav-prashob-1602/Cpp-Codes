#include <iostream>
#include<string>
#include<algorithm>
using namespace std;

/*
https://www.codechef.com/NOV221C/problems/ABSTRING
*/

int main() {
	// your code goes here
	int t,n,count,flag = 1;
	string s;
	cin>>t;
	for(int i=0;i<t;i++) {
	    cin>>n;
	    cin>>s;
	    sort(s.begin(), s.end());
        if(!(n%2)) {
            for(int j=0;j<n;j++) {
                count = 0;
                for(int k=0;k<n;k++) {
                    if (s[j]==s[k]) {
                        count+=1;
                    }
                    else {
                        break;
                    }
                }
                if (count%2) {
                    flag = 0;
                    break;
                }
            }
            if (flag) {
                cout<<"YES";
            }
            else {
                cout<<"NO";
            }
            printf("\n");
            flag = 1;
	    }
        else {
            cout<<"NO\n";
        }
    }
    return 0;
}
