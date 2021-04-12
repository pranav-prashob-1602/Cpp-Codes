#include<stdio.h>
#include<conio.h>

int main(){
	FILE *ptr;
	char str[10];
	ptr=fopen("NEW.TXT","r");
	//clrscr();
	while(!feof(ptr)){
		fgets(str,10,ptr);
		printf("%ld ",ftell(ptr));
	}
	//fseek(ptr,-10,SEEK_CUR);
	//printf("%d",fseek(ptr,50,SEEK_SET));  //fseek returns a integer
	if(fseek(ptr,50,SEEK_CUR)!=0){
		printf("\nUnable to perform fseek()");
	}
	//fseek(ptr,-1*ftell(ptr),SEEK_END);
	//rewind(ptr);
	//printf("\n%ld",ftell(ptr));
	getch();
	return 0;
}
