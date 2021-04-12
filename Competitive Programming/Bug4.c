#include <stdio.h>
#include <math.h>
void is_armstrong(int number)
{
  int i=0,sum=0,rem=0,n=0,p=0,q=0;
  for(i=0;i<=number;i++)
  {
    p=i;
    q=i;
    while(p!=0)
    {
      p=p/10;
      n++;
    }
   while(q!=0)
   {
     rem=q%10;
     sum+=pow(rem,n);
     q=q/10;
   }
   if(sum==i) {
        printf("%d ",sum);
    }
   p=0;
    q=0;
    n=0;
    sum=0;
  }

}
int main() {
	int x;
  scanf("%d",&x);
  is_armstrong(x);
	return 0;
}
