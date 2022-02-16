// #include<iostream>

// using namespace std;

// static int N;
  

  

// bool isSafe(int arr[],int i,int k) 
// { 
//     if(arr[i] & arr[i+1] == 0 && arr[i+1] == 0) {
//         return false;
//     }
//     return true; 
// } 

// bool solveNQUtil(int arr[], int len) 
// { 
    
//     if (len >= N) 
//         return true; 
  
//     for (int i = 0; i < N; i++) { 
//         if (isSafe(arr, i, len)) { 
//             arr[i] = len; 
//             if (solveNQUtil(arr, len + 1)) 
//                 return true; 
//             arr[i] = 0; 
//         } else {
//             arr[i] = len;
//             len++;
//         }
//     } 
//     return false; 
// } 
  
// bool solveNQ() 
// { 
//     int arr[N];
//     arrInitialize(arr);
//     if (solveNQUtil(arr, 1) == false) { 
//         cout<<"-1"<<endl;
//         return false; 
//     }
//     printSolution(arr); 
//     return true; 
// } 


#include <bits/stdc++.h> 
using namespace std; 
  
  
bool isSafe(int arr[],int r) 
{ 
    for(int i=0;i<r;i++) {
        if(arr[i]&arr[i+1] == 0) {
            return false;
        }    
    }
    return true; 
} 

bool permute(int a[], int l, int r)  
{  
    if(isSafe(a,r)) {
        return true;
    }
    if (l == r)  
        return false;  
    else
    {  
        for (int i = l; i <= r; i++)  
        {  
            if(a[l]&a[i] ==0 ) {
                swap(a[l], a[i]);  
                permute(a, l+1, r);  
            }
            permute(a, l+1, r);  
            swap(a[l], a[i]);  
        }  
    }  
    return false;
}  
 
 
void arrInitialize(int arr[],int N) {
    for(int i=0;i<N;i++) {
        arr[i] = i+1;
    }
}

void printSolution(int arr[],int N) 
{ 
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
    if(permute(arr, 0, N-1)) {
        printSolution(arr,N);
    }else {
        cout<<"-1";
    }
    cout<<endl;
    
      
    return 0;  
}  