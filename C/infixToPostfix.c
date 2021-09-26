#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 30

char *intopost(char *);
int precede(char);
int isoperator(char);

typedef struct stk
{
    char data[MAX];
    int  top;
} mystack;

mystack s1;

void init()
{
    s1.top=-1;
}

int isempty()
{
    if(s1.top==-1)
    {
        return 1;
    }
    return 0;
}

int isfull()
{
    if(s1.top==MAX-1)
    {
        return 1;
    }
    return 0;
}

void push(char item)
{
    if(isfull())
    {
        printf("Stack overflow\n");
    }
    else
    {
        s1.data[++s1.top]=item;
        // printf("infix value=%c",s1.data[s1.top]);
    }

}

char pop()
{
    char item;
    if(isempty())
    {
        printf("Stack underflow\n");
        return -1;
    }
    else
    {
        item=s1.data[s1.top--];
        // printf("pop=%c",item);
        return item;
    }
}

char peek()
{
    if(isempty())
    {
        // printf("No elements to show\n");
        return '$';
    }
    return s1.data[s1.top];

}

int isoperator(char ch)
{
    if(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^' || ch=='(' || ch==')')
    {
        return 1;
    }
    return 0;
}

int precede(char ch)
{
    if(ch=='+' || ch=='-')
    {
        return 1;
    }
    if(ch=='*' || ch=='/')
    {
        return 2;
    }
    if(ch=='^')
    {
        return 3;
    }

    return -1;

}

char *intopost(char *infix)
{

    char *postfix=(char *)malloc((strlen(infix)+1)*sizeof(char));
    int i=0,j=0,t;
    while(infix[i]!='\0')
    {
        if(isoperator(infix[i])==0)
        {
            postfix[j]=infix[i];
            i++;
            j++;

        }
        else
        {
            if(infix[i]== '(')
            {
                push(infix[i]);
                i++;
            }

            else if(infix[i]== ')')
            {
                t=peek();
                while(t!='(')
                {
                    postfix[j]= pop();
                    j++;
                    t=peek();
                }
                pop();
                i++;
            }
            else if(precede(infix[i])>precede(peek()))
            {
                push(infix[i]);
                i++;
            }
            else
            {
                postfix[j]=pop();
                j++;
            }
        }
    }
    while(!isempty())
    {
        postfix[j]=pop();
        j++;
    }
    postfix[j]='\0';
    return postfix;
}

int main()
{
    char infiexp[MAX];
    init();
    printf("Enter an infix expression:");
    gets(infiexp);
    //puts(infiexp);
    printf("\nPostfix expression:%s\n",intopost(infiexp));
    //intopost(infiexp);
    return 0;
}
