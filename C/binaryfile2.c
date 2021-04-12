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
    ptr=fopen("EMPLOYEE1.DAT","wb");
    printf("Enter the name");
    gets(e.name);
    fflush(stdin);
    printf("Enter the id");
    scanf("%d",&e.id);
    fflush(stdin);
    printf("Enter the salary");
    scanf("%f",&e.salary);
    fflush(stdin);
    fwrite(&e,sizeof(emp),1,ptr);
    fclose(ptr);
    getch();
    return 0;
}
