/*#include<iostream>
#include<string.h>

using namespace std;

static string s[100];

int StrCount(string cmpStr,int T) {
    int i,c = 0;
    for(i=0;i<T;i++) {
        if(cmpStr.compare(s[i]) == 0) {
            c++;
        }
    }
     return c;
}

int main() {
    int T,Q,i,j,c;
    string str;
    cin>>T;
    for(i=0;i<T;i++) {
        cin>>s[i];
    }
    cin>>Q;
    for(j=0;j<Q;j++) {
        cin>>str;
        c = StrCount(str,T);
        cout<<c<<"\n";
    }
    return 0;
}*/

#include <iostream>
using namespace std;

void PrintArray(int a[],int n,int x)
{
  int i;
  for(i=0;i<n;i++)
  {
      if(x==0) {
        if(a[i]%2==0) {
            cout<<a[i]<<" ";
        }
      } else {
        if(a[i]%2==1) {
        cout<<a[i]<<" ";
        }
      }
  }

}

int main()
{
    int n,i,a[100],x,j,temp;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(i=0;i<n;i++) {
        for(j=0;j<n-1;j++) {
            if(a[j]>a[j+1]) {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    PrintArray(a,n,1);
    PrintArray(a,n,0);
    return 0;
}

