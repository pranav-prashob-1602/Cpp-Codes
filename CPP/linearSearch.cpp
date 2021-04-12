#include<iostream>

using namespace std;

void Lsearch(int a[],int n,int data) {
    int pos=-1;
    for(int i=0;i<n;i++) {
        if(a[i]==data) {
            pos=i+1;
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
    Lsearch(a,n,x);
    return 0;
}


