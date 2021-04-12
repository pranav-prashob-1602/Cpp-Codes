#include<stdio.h>
#include<conio.h>

typedef struct employee {
    int id;
    char name[30];
    int salary;
}emp;

void input() {
    FILE *ptr = fopen("EMP.DAT","ab+");
    emp rec;
    printf("INPUT DATA");
     scanf("%s",rec.name);
    fflush(stdin);
    scanf("%d %d ",&rec.id,&rec.salary);
    fflush(stdin);
    fwrite(&rec,sizeof(emp),1,ptr);
    fclose(ptr);
}

void update() {
    FILE *ptr=fopen("EMP.DAT","rb+");
    fseek(ptr,0,SEEK_SET);
    emp rec;
    int id,flag=0;
    printf("Enter the id: ");
    scanf("%d",&id);
    fflush(stdin);
    fread(&rec,sizeof(emp),1,ptr);
    while(!feof(ptr)) {
        if(rec.id==id) {
            scanf("%d ",&rec.salary);
            fflush(stdin);
            fseek(ptr,-1*sizeof(emp),SEEK_CUR);
            fwrite(&rec,sizeof(emp),1,ptr);
            flag=1;
            break;
        }
        fread(&rec,sizeof(emp),1,ptr);
    }
    fclose(ptr);
    if(!flag){
            printf("ID NOT FOUND\n");
        printf("Enter  a valid  id\n");
        update();
    }
}

void display() {
    FILE *ptr=fopen("EMP.DAT","rb");
    emp rec;
    fread(&rec,sizeof(emp),1,ptr);
    while(!feof(ptr)) {
        printf("EMPLOYEE DETAILS\nID: %d\nNAME: %s\n SALARY: %d\n",rec.id,rec.name,rec.salary);
        fread(&rec,sizeof(emp),1,ptr);
    }
    fclose(ptr);
}

int main() {
    //input();
    display();
    //update();
    //display();
    getch();
    return 0;
}
