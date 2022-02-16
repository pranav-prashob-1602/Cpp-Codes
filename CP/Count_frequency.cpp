#include <iostream>
#include<map>

using namespace std;

struct val {
    int a,b;
};

int main()
{
    int x,k=0,flag;
    map <int,struct val> m;
    val v;
    for(int i=0;i<8;i++) {
        cin>>x;
        flag =1;
        for(auto it = m.begin(); it!=m.end(); it++) {
            if(it->second.a == x) {
                flag =0;
                it->second.b++;
                break;
            }
        }
        if(flag) {
            v.a = x;
            v.b = 1;
            m.insert(pair<int,struct val>(i,v));
        }
    }
    for(auto it = m.begin();it !=m.end();it++) {
       cout<<it->second.a<<" "<<it->second.b<<endl;
    }
    return 0;
}