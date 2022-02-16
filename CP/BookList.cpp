#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector <int> v;
    long long int n,q,z,x,k;
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>x;
        v.push_back(x);
    }
    cin>>q;
    while(q--) {
        cin>>k;
        x =1;
        for (auto it = v.begin(); it != v.end(); ++it,x++) {
            if(x == k){
                cout <<*it<<endl;
                v.erase(it);
                break;
            }
            
        }
    }
}