#include<stdio.h>
#include<conio.h>
#include<string.h>

int main() {

    FILE *ptr = fopen("HOMEWORK.TXT","r");
    FILE *fp = fopen("HOMEWORK.TXT","r");
    char str[100],str1[100],occ[20][100];
    int num=0,k=0,flag=1,i;
    while(!feof(ptr)) {
        fscanf(ptr,"%s",str);
        fseek( fp,0,SEEK_SET);
        num=0;
        flag=1;
        for(i=0;i<k;i++) {
            if(!strcmpi(occ[i],str)) {
                flag=0;
            }
        }
        if(flag) {
            while(!feof(fp)) {
                fscanf(fp,"%s",str1);
                if(!strcmpi(str,str1)) {
                    num++;
                }
            }
            if(num>1) {
                strcpy(occ[k],str);
                k++;
            }
            printf("%s : %d\n",str,num);
        }
    }
    fclose(ptr);
    fclose(fp);
    getch();
    return 0;
}
