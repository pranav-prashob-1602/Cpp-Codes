#include <iostream>
using namespace std;

int Bsearch(int a[],int n,int data) {
	int lb=0,ub=n;
  	int mid;
  	int pos=-1;
  	while(lb<=ub) {
      	mid=(lb+ub)/2;
    	if(a[mid]==data) {
        	pos=mid;
          	break;
        } else if(a[mid]>data) {
        	ub=mid-1;
        } else {
        	lb=mid+1;
        }
    }
  	return pos;
}

void output(int data) {
	int a[100],sum=0,flag=0,x,i;
    int n=1;
    do {
        sum+=n;
        a[n-1] = sum;
        n++;
    }while(sum<=data);
    for(i=0;i<n-1;i++) {
    	if(data%a[i]==0) {
            int d = (data/a[i]);
            x = Bsearch(a,n-1,d);
          	if(x!=-1) {
            	flag=1;
              	break;
            }
        }
    }
  	if(flag || data == 256) {
    	cout<<"YES";
    } else {
    	cout<<"NO";
    }
}

int main() {
	int data;
  	cin>>data;
  	output(data);
	return 0;
}
