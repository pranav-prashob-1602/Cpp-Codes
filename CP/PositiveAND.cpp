#include <bits/stdc++.h> 
using namespace std; 
  
  
bool isSafe(int arr[],int N,int ind) 
{ 
    if(arr[ind]&arr[ind-1] == 0) {
        return false;
    }
    for(int i=0;i<N;i++) {
        if(ind==arr[i]) {
            return false;
        } 
    }
    return true; 
} 

bool permute(int arr[],int l,int N) {  
    if(l==N) {
        return false;
    }
    for(int i=1;i<=N;i++) {
        arr[l-1] = i;
        if(i>=2) {
            if(isSafe(arr,N,i)) {
                if(permute(arr,l+1,N)) {
                    return true;
                }
            }
        }
    }
}  
 
 
void arrInitialize(int arr[],int N) {
    for(int i=0;i<N;i++) {
        arr[i] = -1;
    }
}

void printSolution(int arr[],int N) { 
    for (int i = 0; i < N; i++) { 
      cout<<arr[i]<<" ";
    } 
    cout<<endl;
}  
 
int main()  
{  
    int N;
    cin>>N;
    int arr[N];
    arrInitialize(arr,N);
    if(permute(arr, 1, N)) {
        printSolution(arr,N);
    }else {
        cout<<"-1";
    }
    cout<<endl;
    
      
    return 0;  
}  