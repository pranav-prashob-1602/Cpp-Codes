#include<bits/stdc++.h>

/*

shinchanCoder Here!!

*/

using namespace std;

#define pb push_back
#define all(x) begin(x), end(x)
#define allr(x) rbegin(x), rend(x)

#define sz(x) (int)(x).size()

#define ff first
#define ss second

#define mp make_pair

#define ll long long
#define ld long double
#define lli long long int

#define mod 1000000007


void display(ll arr[],ll n) {
    for(ll i=0;i<n;i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void heapDelete(ll arr[],ll n) {
    swap(arr[0],arr[n]);
    ll i=0,x;
    while(i<n && ((arr[i]<arr[i*2+1] && i*2+1<n) || (arr[i]<arr[i*2+2] && i*2+2<n))) {
        if((arr[i]<arr[i*2+1] && i*2+1<n) && (arr[i]<arr[i*2+2] && i*2+2<n)) {
            x = arr[i*2+1]>arr[i*2+2] ? i*2+1 : i*2+2;
        }else if(arr[i]<arr[i*2+1] && i*2+1<n) {
            x=i*2+1;
        }else {
            x=i*2+2;
        }
        swap(arr[i],arr[x]);
        i=x;
    }
}

void deleteHeap(ll arr[],ll n) {
    for(ll i=n-1;i>0;i--) {
        heapDelete(arr,i);
        display(arr,n);
    }
}

void heapInsert(ll arr[],ll n) {
    ll i=n;
    while(arr[i]>arr[i/2] && i!=0) {
        swap(arr[i],arr[i/2]);
        i/=2;
    }
}

void createHeap(ll n) {
    ll arr[n],x;
    memset(arr,-1,sizeof(arr));
    cin>>arr[0];
    for(ll i=1;i<n;i++) {
        cin>>x;
        arr[i] = x;
        heapInsert(arr,i);
    }
    for(ll i=0;i<n;i++) {
        cout<<arr[i]<<" ";
    }
    cout<<"\n\nDelete :"<<endl;
    deleteHeap(arr,n);
}

void heapify(ll arr[],ll n,ll ind) {
    ll mx=ind,l=ind*2+1,r=ind*2+2;
    if(l<n && arr[l]>arr[mx]) {
        mx=l;
    }
    if(r<n && arr[r]>arr[mx]) {
        mx=r;
    }
    swap(arr[mx],arr[ind]);
    if(mx!=ind) {
        heapify(arr,n,mx);
    }
}

void createHeapify(ll n) {
    ll arr[n],x;
    memset(arr,-1,sizeof(arr));
    for(ll i=0;i<n;i++) {
        cin>>arr[i];
    }
    for(ll i=(n/2)-2;i>=0;i--) {
        heapify(arr,n,i);
    }
    display(arr,n);
    //deleteHeap(arr,n);
}

int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin>>n;
    createHeap(n);
    createHeapify(n);
    return  0;
}

/*
7
40 15 35 30 10 5 25
*/
