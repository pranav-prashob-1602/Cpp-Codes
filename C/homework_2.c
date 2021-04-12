#include<stdio.h>
#include<conio.h>

typedef struct date {
    int d;
    int m;
    int y;
}Date;

Date today;

typedef struct customer {
     int accNo;
    char name[50];
    char address[50];
    char accState; // C,D,O
    float newBalance;
    float oldBalance;
    Date lastPayment;
    Date dueDate;
}record;

char accStateCalc(Date due,float balance,float amountPaid,char state) {
    float minVal;
    if(amountPaid!=0) {
        minVal=balance*0.1;
        if(minVal>=amountPaid) {
            return 'D';
        }else {
            return 'C';
        }
    } else{
        if(today.y>=due.y) {
            if(today.m>due.m) {
                return 'O';
            }else if(today.m == due.m) {
                if(today.d > due.d) {
                    return 'O';
                }else {
                    return state;
                }
            }else {
                return state;
            }
        }else {
            return state;
        }
    }
}


void newPayment() {
    FILE *ptr=fopen("CUSTOMER.DAT","rb+");
    record cus;
    int no,flag=0;
    float amt;
    printf("-->Enter the ACC No. : \t");
    scanf("%d",&no);
    fflush(stdin);
    fread(&cus,sizeof(record),1,ptr);
    while(!feof(ptr)) {
        if(cus.accNo == no) {
            flag=1;
            printf("\n\n\n-->ACC No. :\t%d\n",cus.accNo);
            cus.accState=accStateCalc(cus.dueDate,cus.newBalance,0,cus.accState);
            printf("-->ACC State :\t%c\n",cus.accState);
            printf("-->Name :\t%s\n",cus.name);
            printf("-->Address :\t%s\n",cus.address);
            printf("\n\n\n-->Enter the amount paid:\t");
            scanf("%f",&amt);
            fflush(stdin);
            cus.accState=accStateCalc(cus.dueDate,cus.newBalance,amt,cus.accState);
            cus.oldBalance=cus.newBalance;
            cus.newBalance+=amt;
            cus.lastPayment.d=today.d;
            cus.lastPayment.m=today.m;
            cus.lastPayment.y=today.y;
            printf("-->Enter the new due Date\n-->");
            scanf("%d %d %d",&cus.dueDate.d,&cus.dueDate.m,&cus.dueDate.y);
            fflush(stdin);
            fseek(ptr,-1*sizeof(record),SEEK_CUR);
            fwrite(&cus,sizeof(record),1,ptr);
            printf("\n\n\n\t\tPAYMENT SUCCESSFUL!!");
            getch();
            break;
        }
        fread(&cus,sizeof(record),1,ptr);
    }
    if(!flag) {
        printf("\n\n\tENTER A VALID ACC NO. ");
    }
    fclose(ptr);

}

void addDetails() {
    FILE *ptr=fopen("CUSTOMER.DAT","ab");
    record cus;
    fseek(ptr,0,SEEK_END);
    printf("-->ACC No. :\t");
    scanf("%d",&cus.accNo);
    fflush(stdin);
    printf("-->Name :\t");
    gets(cus.name);
    fflush(stdin);
    printf("-->Address :\t");
    gets(cus.address);
    fflush(stdin);
    printf("-->Balance :\t");
    scanf("%f",&cus.newBalance);
    fflush(stdin);
    cus.oldBalance=cus.newBalance;
    cus.lastPayment.d=today.d;
    cus.lastPayment.m=today.m;
    cus.lastPayment.y=today.y;
    printf("-->Enter due Date\n-->");
    scanf("%d %d %d",&cus.dueDate.d,&cus.dueDate.m,&cus.dueDate.y);
    fflush(stdin);
    cus.accState='C';
    fwrite(&cus,sizeof(record),1,ptr);
    fclose(ptr);
}

void editDetails() {
    FILE *ptr=fopen("CUSTOMER.DAT","rb+");
    record cus;
    int no,flag=0,n;
    char str[50];
    printf("\n\n-->Enter the ACC No. : \t");
    scanf("%d",&no);
    fflush(stdin);
    fread(&cus,sizeof(record),1,ptr);
    while(!feof(ptr)) {
        if(cus.accNo == no) {
            flag=1;
            printf("\n\n-->MAIN MENU\n");
            printf("-->Press 1 to edit Name\n");
            printf("-->Press 2 to edit Address\n");
            printf("\n-->Enter your choice\n-->");
            fflush(stdin);
            scanf("%d",&n);
            fflush(stdin);
            if(n==1) {
                printf("\n\n-->Enter Name :\t");
                gets(cus.name);
                fflush(stdin);
                fseek(ptr,-1*sizeof(record),SEEK_CUR);
                fwrite(&cus,sizeof(record),1,ptr);
            }else if(n==2){
                printf("\n\n-->Enter address :\t");
                gets(cus.address);
                fflush(stdin);
                fseek(ptr,-1*sizeof(record),SEEK_CUR);
                fwrite(&cus,sizeof(record),1,ptr);
            }else {
                flag=-1;
            }
            break;
        }
        fread(&cus,sizeof(record),1,ptr);
    }
    if(!flag) {
        printf("\n\n\tENTER A VALID ACC NO. ");
    }else if(flag==-1) {
        printf("\n\n\tENTER A VALID CHOICE!!\n");
    }else {
        printf("\n\n\tUPDATED SUCCESSFULLY!");
    }
    fclose(ptr);
}

void viewDetails() {
    FILE *ptr=fopen("CUSTOMER.DAT","rb");
    record cus;
    int no,flag=0;
    printf("-->Enter the ACC No. : \t");
    scanf("%d",&no);
    fflush(stdin);
    fread(&cus,sizeof(record),1,ptr);
    while(!feof(ptr)) {
        if(cus.accNo == no) {
            flag=1;
            printf("\n\n\n-->ACC No. :\t%d\n",cus.accNo);
            cus.accState=accStateCalc(cus.dueDate,cus.newBalance,0,cus.accState);
            printf("-->ACC State :\t%c\n",cus.accState);
            printf("-->Name :\t%s\n",cus.name);
            printf("-->Address :\t%s\n",cus.address);
            printf("-->Balance :\t%f\n",cus.newBalance);
            printf("-->Last Payment Date:\t%d - %d - %d\n",cus.lastPayment.d,cus.lastPayment.m,cus.lastPayment.y);
            printf("-->Payment Due Date:\t%d - %d - %d\n",cus.dueDate.d,cus.dueDate.m,cus.dueDate.y);
            fseek(ptr,-1*sizeof(record),SEEK_CUR);
            fwrite(&cus,sizeof(record),1,ptr);
            break;
        }
        fread(&cus,sizeof(record),1,ptr);
    }
    if(!flag) {
        printf("\n\n\tACC NO. NOT FOUND!!\n\nENTER A VALID ACC NO. ");
    }
    fclose(ptr);
}

void deleteDetails() {
    FILE *ptr=fopen("CUSTOMER.DAT","rb");
    FILE *fp=fopen("TEMP.DAT","wb+");
    record cus;
    int no,flag=0;
    printf("-->Enter the ACC NO. to be DELETED : \t");
    scanf("%d",&no);
    fflush(stdin);
    fread(&cus,sizeof(record),1,ptr);
    while(!feof(ptr)) {
        if(cus.accNo != no) {
                fwrite(&cus,sizeof(record),1,fp);
        }else {
            flag=1;
        }
        fread(&cus,sizeof(record),1,ptr);
    }
    fclose(ptr);
    fclose(fp);
    if(!flag) {
        printf("\n\n\tACC NO. NOT FOUND!!\n\nENTER A VALID ACC NO. ");
        remove("TEMP.DAT");
    }else {
        printf("\n\n\tDELETED SUCCESSFULLY!!\n\n");
        remove("CUSTOMER.DAT");
        rename("TEMP.DAT","CUSTOMER.DAT");
    }
}

int main() {
    char ch='Y';
    int n;
    printf("-->Enter today's Date\n-->");
    scanf("%d %d %d", &today.d, &today.m, &today.y);
    fflush(stdin);
    do{
        printf("\n\nMAIN MENU\n\n");
        printf("-->Press 0 for NEW PAYMENT\n");
        printf("-->Press 1 to ADD new customer\n");
        printf("-->Press 2 to EDIT details\n");
        printf("-->Press 3 to DELETE a customer\n");
        printf("-->Press 4 to VIEW details\n");
        printf("-->Press 5 to EXIT\n");
        printf("\n-->Enter your choice\n-->");
        fflush(stdin);
        scanf("%d",&n);
        fflush(stdin);
        switch(n) {
        case 0:
            newPayment();
            break;
        case 1:
            addDetails();
            break;
        case 2:
            editDetails();
            break;
        case 3:
            deleteDetails();
            break;
        case 4:
            viewDetails();
            break;
        case 5:
            printf("\n\n-->BYE!\n-->HAVE A NICE DAY AHEAD!!");
            printf("\n\n\n\t\t\tPRESS ENTER TWICE !");
            getch();
            return 0;
        default:
           printf("\n-->Enter a valid choice!!!");
        }
        printf("\n\n\n-->Do you want to continue?(Y/N)\n\n-->");
        scanf("%c",&ch);
        printf("\n\n\n");
    }while(ch=='Y' || ch=='y') ;
     printf("\n\n-->BYE!\n-->HAVE A NICE DAY AHEAD!!");
     printf("\n\n\n\t\t\tPRESS ENTER!");
     getch();
    return 0;
}

