#include <iostream>

using namespace std;

int main()
{
    int T,A,N[5][5],i,j,k,g=0,h=0,sum=0;
    cin>>T;

 for(i=0;i<T;i++)
 {
     cin>>A;
     sum=0;
     g=0;
     h=0;

     for(j=0;j<A;j++)
     {
         for(k=0;k<A;k++)
         {
             cin>>N[j][k];
             if(j==k)
             {sum+=N[j][k];}
         }
     }

    for(j=0;j<A;j++)
     {
         for(k=0;k<A;k++)
         {
           if(N[j][k]==N[j][k+1])
           { g++;}
           else if(N[j][k]==N[j+1][k])
           { h++;}
         }
     }

     cout<<sum<<" "<<g<<" "<<h<<"\n";
 }

return 0;
}
