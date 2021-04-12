#include<stdio.h>
#include<stdlib.h>
typedef struct emp{
    char name[30];
    char id[10];
    int sal;
}a;
 void main()
 {
        int n,i;
        printf("Enter the number of records");hg
        scanf("%d",&n);
        a *p=(a *)malloc(n*sizeof(a));
        for(i=0;i<n;i++)
        {
            gets((p+i)->name);
            fflush(stdin);
            gets((p+i)->id);
            fflush(stdin);
            scanf("%d",&((p+i)->sal));
            fflush(stdin);
        }
        /*while(n!=0)
        {
            gets(p->name);
            fflush(stdin);
            gets(p->id);
            fflush(stdin);
            scanf("%d",&(p->sal));
            p++;
            n--;
        }*/
        for(i=0;i<n;i++)
        {
            puts((p+i)->name);
            puts((p+i)->id);
            printf("%d",(p+i)->sal);
        }
 }

