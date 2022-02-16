#include <iostream>
#include <string>
#include<queue>

using namespace std;

struct Team {
    string name;
    int gs=0,gc=0,gd=0,points=0;
};

struct CompareGD { 
    bool operator()(Team const& p1, Team const& p2) 
    { 
        // return "true" if "p1" is ordered  
        // before "p2", for example: 
	if(p1.points == p2.points) {
		return p1.gd < p2.gd;
	}
        return p1.points < p2.points; 
    } 
}; 

int main()
{
    int x,y,i,j,T;
    string str,s1,s2;
    priority_queue <Team, vector<Team>, CompareGD> Q;
    priority_queue <Team, vector<Team>, CompareGD> Q2;
    cin>>T;
    for(i=1;i<=T*12;i++) {
        // cout<<"a"<<" ";
        // if((i-1)%12 == 0 && i!=0){
        //     for(j=0;j<2;j++) {
        //         Team t = Q.top();
        //         Q.pop();
        //         cout<<t.name<<" ";
        //     }cout<<"\n";
        //     Q = priority_queue <Team, vector<Team>, CompareGD> ();
        //     Q2 = priority_queue <Team, vector<Team>, CompareGD> ();
        // }
        Team t1,t2;
        cin>>t1.name;
        cin>>t1.gs;
        cin>>str;
        cin>>t2.gs;
        cin>>t2.name;
        t1.gc = t2.gs;
        t2.gc = t1.gs;
        t1.gd = t1.gs - t1.gc;
        t2.gd = t2.gs - t2.gc;
        if(t1.gs > t2.gs) {
            t1.points = 3;
            t2.points = 0;
        } else if(t1.gs == t2.gs) {
            t1.points = 1;
            t2.points = 1;
        } else {
            t1.points = 0;
            t2.points = 3;
        }
        if(Q.empty()){
            Q.push(t1);
            Q.push(t2);
            // cout<<t1.name<<" "<<t1.gd<<"\n";
            // cout<<t2.name<<" "<<t2.gd<<"\n";
        } else {
            Team x;
            int flag1 = 0;
            int flag2 = 0;
            while(!Q.empty()) {
                x = Q.top();
                Q.pop();
                if(x.name.compare(t1.name) == 0) {
                    flag1 = 1;
                    x.gs = x.gs + t1.gs;
                    x.gc = x.gc + t1.gc;
                    x.gd = x.gd + t1.gd;
                    x.points = x.points + t1.points;
                } 
                if(x.name.compare(t2.name) == 0) {
                    flag2 = 1;
                    x.gs = x.gs + t2.gs;
                    x.gc = x.gc + t2.gc;
                    x.gd = x.gd + t2.gd;
                    x.points = x.points + t2.points;
                }
                Q2.push(x);
            }
            if(!flag1) {
                Q2.push(t1);
            }
            if(!flag2) {
                Q2.push(t2);
            }
            while(!Q2.empty()) {
                x = Q2.top();
                // cout<<x.name<<" "<<x.gd<<"\n";
                Q2.pop();
                Q.push(x);
            }
            if(i%12 == 0) {
                t1 = Q.top();
                Q.pop();
                t2 = Q.top();
                s1 = t1.name;
                s2 = t2.name;
                if(t1.points == t2.points) {
                    if(t1.gd < t2.gd) {
                        s2 = t1.name;
                        s1 = t2.name;
                    }
                }
                cout<<s1<<" "<<s2<<"\n";
                Q = priority_queue <Team, vector<Team>, CompareGD> ();
                Q2 = priority_queue <Team, vector<Team>, CompareGD> ();
            }
        }
        
    }
    return 0;
}