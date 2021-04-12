#include<stdio.h>
#include<conio.h>

typedef struct employee {
    char name[50];
    int id;
    float salary;
}emp;

int main() {
    emp e,e1;
    FILE *ptr,*fp;
    ptr=fopen("EMPLOYEE.TXT","w");
    printf("Enter the name");
    gets(e.name);
    fflush(stdin);
    printf("Enter the id");
    scanf("%d",&e.id);
    fflush(stdin);
    printf("Enter the salary");
    scanf("%f",&e.salary);
    fflush(stdin);
    fprintf(ptr,"%s %d %f",e.name,e.id,e.salary);
    fclose(ptr);
    fp=fopen("EMPLOYEE.TXT","r");
    while(fscanf(fp,"%s %d %f",e.name,&e.id,&e.salary)!=EOF) {
        printf("%s %d %f",e.name,e.id,e.salary);
    }
    //fclose(ptr);
    fclose(fp);
    getch();
    return 0;
}
