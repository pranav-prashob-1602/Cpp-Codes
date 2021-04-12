#include<iostream>

 using namespace std;

 void Bsearch(int a[],int n,int data) {
    int pos=-1;
    int lb=0,ub=n,mid;
    while(lb<=ub) {
        mid=(lb+ub)/2;
        if(a[mid]==data) {
            pos=mid+1;
            break;
        }else if(a[mid] > data) {
            ub =mid-1;
        } else {
            lb=mid+1;
        }
    }
    if(pos==-1) {
        cout<<"Element not Found!!";
        return;
    }
    cout<<"Element found at "<<pos;
 }

 int main() {
    int a[100],n,x;
    cout<<"Enter the size of array :";
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    cout<<"\nEnter the number to be searched :";
    cin>>x;
    Bsearch(a,n,x);
    return 0;
}

