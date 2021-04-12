#include<stdio.h>
#include<conio.h>

typedef struct employee {
    char name[50];
    int id;
    float salary;
}emp;

int main() {
    emp e;
    FILE *ptr,*fp;
    ptr=fopen("EMPLOYEE1.DAT","rb");
    /*printf("Enter the name");
    gets(e.name);
    fflush(stdin);
    printf("Enter the id");
    scanf("%d",&e.id);
    fflush(stdin);
    printf("Enter the salary");
    scanf("%f",&e.salary);
    fflush(stdin);*/
    while(fread(&e,sizeof(emp),1,ptr)==1){
            printf("%s %d %f\n",e.name,e.id,e.salary);
    }
    fclose(ptr);
    getch();
    return 0;
}

