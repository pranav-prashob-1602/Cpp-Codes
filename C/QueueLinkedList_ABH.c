#include<stdio.h>
#include<stdlib.h>
#define SIZE 15

typedef struct node
{
    int data;
    struct node *next;
} NODE;

NODE *front=NULL;
NODE *rear=NULL;

void enQueue();
int deQueue();
int peek();
void display();


int main()
{

    int choice,val;
    do
    {
        printf("\nLINKED LIST  QUEUE OPERATIIONS\n");
        printf("\n1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY\n4.PEEK\n5.EXIT");
        printf("\nEnter the choice:");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            enQueue();
            break;
        case 2:
            val=deQueue();
            if(val!=-1)
            {
                printf("\nthe popped value=%d",val);
            }
            break;
        case 3:
            display();
            break;
        case 4:
            val=peek();
            if(val!=-1)
            {
                printf("\nthe peek value=%d",val);
            }
            break;
        case 5:
            printf("\nBYE....");
            exit(0);
            break;
        default:
            printf("\nplease enter valid choice");
        }
    }
    while(choice!=0);
    return 0;
}


void enQueue()
{
    NODE *p;
    p=(NODE *)malloc(sizeof(NODE));
    if(p==NULL)
    {
        printf("\nERROR OCCURRED WHILE INITIALISING!");
        return;
    }
    printf("\nEnter the value of the node to be pushed:");
    scanf("%d",&p->data);
    p->next=NULL;
    if(front==NULL)
    {
        front=p;
        rear=p;
    }
    else
    {
        rear->next=p;
        rear=p;
    }
}


int deQueue()
{
    int val=-1;
    NODE *q;
    if(front==NULL)
    {
        printf("\nQUEUE UNDERFLOW");
    }
    else
    {
        q=front;
        front=front->next;
        if(front==NULL)
        {
            rear=NULL;
        }
        val=q->data;
        free(q);
    }
    return val;
}


int peek()
{
    if(front==NULL)
    {
        printf("\nQUEUE UNDERFLOW");
        return -1;
    }
    return front->data;
}


void display()
{
    NODE *q;
    if((front==NULL)&&(rear==NULL))
    {
        printf("\nEMPTY QUEUE!");
    }
    else
    {
        q=front;
        while(q!=NULL)
        {
            printf("%d",q->data);
            //printf("\nabc");
            q=q->next;
            if(q != NULL) {
                printf(" -> ");
            }
        }
    }
}
