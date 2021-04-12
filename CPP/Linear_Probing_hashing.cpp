#include<bits/stdc++.h>

/*

shinchanCoder Here!!

*/

using namespace std;

#define pb push_back
#define all(x) begin(x), end(x)

#define sz(x) (int)(x).size()

#define ff first
#define ss second

#define mp make_pair

#define ll long long
#define ld long double

#define mod 1000000007

int Hash(int    key) {
    return key%10;
}

int probe(int ht[],int key) {
    int ind = Hash(key);
    int i = 1;
    while(ht[(ind+i)%10]!=0) { //to make it generalized, define the size of the hash table global
        i++;
    }
    return (ind+i)%10;
}

void Insert(int ht[],int key) {
    int ind = Hash(key);
    if(ht[ind]!=0) {
        ind = probe(ht,key);
    }
    ht[ind] = key;
}

int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int ht[10] = {0};
    int T = 5,k;
    while(T--) {
        cin>>k;
        Insert(ht,k);
    }
    for(ll i=0;i<10;i++) {
        cout<<ht[i]<<" ";
    }
    return 0;
}
