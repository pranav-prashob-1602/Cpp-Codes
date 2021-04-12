#include<iostream>

using namespace std;

int main() {
    int d, t,s,sum,sum1,flag,k,min_val,max_val,m;
    cin>>d>>t;
    sum = 0;
    sum1 = 0;
    flag =0;
    k=0;
    int arr[300];
    for(int i=0;i<d;i++) {
        cin>>min_val>>max_val;
        arr[k] = min_val;
        arr[k+1] = max_val;
        k+=2;
        sum+=max_val;
        sum1+=min_val;
    }
    if(sum>=t && sum1<t) {
            flag =1;
    }
    if(flag) {
        cout<<"YES\n";
        m=1;
        s = arr[m];
        cout<<arr[m]<<" ";
        for(int j=1;j<d;j++) {
            t=t-s;
            cout<<t<<"\n";
            s = t;
        }
    }else {
        cout<<"NO";
    }
}

