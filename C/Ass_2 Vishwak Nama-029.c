#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int asd = 0;
struct Node
{
 int num;
 struct Node *nxt;
} *head;
int count = -1;

bool
EmptyList ()
{
 if (head == NULL)
  return true;

 else
  return false;
}

void
insert ()
{
 int a;
 scanf ("%d", &a);
 struct Node *curr;
 struct Node *neww;
 neww = (struct Node *) malloc (sizeof (struct Node));
 curr = (struct Node *) malloc (sizeof (struct Node));

 neww->num = a;
 neww->nxt = NULL;
 if (head == NULL)
  {
   head = neww;
   count += 1;
  }
 else
  {
   curr = head;
   while (curr->nxt != NULL)
	{
	 curr = curr->nxt;
	}
   curr->nxt = neww;
   count += 1;
  }
}

void
Insert ()
{
 int a;
 printf ("Insert the integer number to be inserted\n");
 scanf ("%d", &a);
 struct Node *curr;
 struct Node *neww;
 neww = (struct Node *) malloc (sizeof (struct Node));
 curr = (struct Node *) malloc (sizeof (struct Node));

 neww->num = a;
 neww->nxt = NULL;
 if (head == NULL)
  {
   head = neww;
   printf ("node%d inserted\n", a);
   count += 1;
  }
 else
  {
   curr = head;
   while (curr->nxt != NULL)
	{
	 curr = curr->nxt;
	}
   curr->nxt = neww;
   count += 1;
   printf ("node%d inserted\n", a);
  }
 printf ("To insert another value press 1 else 0\n");
 int x;
 scanf ("%d", &x);
 if (x == 1)
  Insert ();
 else
  return;
}

void
Insertnxt ()
{
 int a, f = 0, n;

 printf ("\nInsert the integer number to be Inserted\n");
 scanf ("%d", &n);
 printf ("Insert The position after which the num is to be inserted\n");
 scanf ("%d", &a);
 struct Node *curr;
 struct Node *neww;
 neww = (struct Node *) malloc (sizeof (struct Node));
 curr = (struct Node *) malloc (sizeof (struct Node));
 neww->num = n;
 if (head == NULL)
  {
   printf ("\nList is Empty\n");
  }
 else
  {
   for (curr = head; curr->nxt != NULL; curr = curr->nxt)
	{
	 if (curr->num == a)
	  {
	   neww->nxt = curr->nxt;
	   curr->nxt = neww;
	   count += 1;
	   f = 1;
	  }
	}
   if (curr->num == a)
	{
	 neww->nxt = NULL;
	 curr->nxt = neww;
	 count += 1;
	 f = 1;
	}
  }
 if (f == 1)
  printf ("\nNode value %d Inserted\n", n);
 else
  printf ("%dNum Not fount to insert %d\n", a, n);
 printf ("To Insert another value after ant number press 1 else 0\n");
 int x;
 scanf ("%d", &x);
 if (x == 1)
  Insertnxt ();
 else
  return;
}

void
Insertpos ()
{
 int a, f = 0, c = 0, n;
 printf ("\nInsert the integer number to be Inserted\n");
 scanf ("%d", &n);
 printf ("Insert The index in which the num is to be inserted\n");
 scanf ("%d", &a);
 struct Node *curr;
 struct Node *neww;
 neww = (struct Node *) malloc (sizeof (struct Node));
 curr = (struct Node *) malloc (sizeof (struct Node));
 neww->num = n;
 if (a == 0)
  {
   neww->nxt = head;
   head = neww;
   f = 1;
   count += 1;
  }
 else if (a == count + 1)
  {
   for (curr = head; curr->nxt != NULL; curr = curr->nxt)
	{

	}
   neww->nxt = NULL;
   curr->nxt = neww;
   count += 1;
   f = 1;
  }
 else if (a > count)
  printf ("Node Not found\n");
 else
  {
   for (curr = head; c <= a; c++)
	{
	 curr = curr->nxt;
	}
   neww->nxt = curr->nxt;
   f = 1;
   curr->nxt = neww;
   count += 1;
  }

 if (f == 1)
  printf ("\nNode position %d Inserted\n", a);


 printf ("To Insert another node at an Index press 1 else 0\n");
 int x;
 scanf ("%d", &x);
 if (x == 1)
  Insertpos ();
 else
  return;
}

void
Deleteval ()
{
 int a, f = 0;
 printf ("\nInsert the value to be Deleted\n");
 scanf ("%d", &a);
 struct Node *curr;
 struct Node *neww = head;
 neww = (struct Node *) malloc (sizeof (struct Node));
 curr = (struct Node *) malloc (sizeof (struct Node));
 if (head->num == a)
  {
   head = head->nxt;
   count -= 1;
   f = 1;
  }
 else
  {
   neww = head;
   for (curr = head->nxt; curr->nxt != NULL; curr = curr->nxt)
	{
	 if (curr->num == a)
	  {
	   neww->nxt = curr->nxt;
	   count -= 1;
	   f = 1;
	  }
	 neww = neww->nxt;
	}
   if (curr->num == a)
	{
	 neww->nxt = NULL;
	 count -= 1;
	 f = 1;
	}
  }
 if (f == 1)
  printf ("\nNode value %d Deleted\n", a);
 else
  printf ("Node value %d Not found\n", a);
 printf ("To Delete another value press 1 else 0\n");
 int x;
 scanf ("%d", &x);
 if (x == 1)
  Deleteval ();
 else
  return;
}

void
Deletepos ()
{
 int a, f = 0, c = 0;
 printf ("\nInsert the Index value to be Deleted\n");
 scanf ("%d", &a);
 struct Node *curr;
 struct Node *neww = head;
 neww = (struct Node *) malloc (sizeof (struct Node));
 curr = (struct Node *) malloc (sizeof (struct Node));
 if (a > count)
  printf ("Index Not found\n");
 else
  {
   if (a == 0)
	{
	 head = head->nxt;
	 f = 1;
	 count -= 1;
	}
   else
	{
	 for (curr = head; c < a - 1; c++)
	  {
	   curr = curr->nxt;
	  }
	 curr->nxt = curr->nxt->nxt;
	 count -= 1;
	}
   printf ("\nIndex %d Deleted\n", a);
  }

 printf ("To delete another Index press 1 else 0\n");
 int x;
 scanf ("%d", &x);
 if (x == 1)
  Deletepos ();
 else
  return;
}

void
Delete1 ()
{
 head = head->nxt;
 count -= 1;
 printf ("Node Index 0 Deleted\n");
}

void
Deletelast ()
{
 if (head->nxt == NULL)
  {
   Delete1 ();
  }
 else
  {
   struct Node *curr;
   curr = (struct Node *) malloc (sizeof (struct Node));
   curr = head;
   while (curr->nxt->nxt != NULL)
	{
	 curr = curr->nxt;
	}
   curr->nxt = NULL;
   count -= 1;
   printf ("Last Node Deleted\n");
  }
}

void
Display ()
{
 struct Node *curr;
 curr = (struct Node *) malloc (sizeof (struct Node));

 if (head == NULL)
  {
   printf ("\nLinked list is Empty\n");
  }
 else
  {
   curr = head;
   while (curr != NULL)
	{
	 printf ("->%d", curr->num);
	 curr = curr->nxt;
	}
   printf ("\n");
  }

}

struct Node *
SortedMerge (struct Node *a, struct Node *b)
{

 if (a == NULL)
  return b;

 else if (b == NULL)
  return a;

 struct Node *result = NULL;


 if (a->num <= b->num)
  {
   result = a;
   result->nxt = SortedMerge (a->nxt, b);
  }
 else
  {
   result = b;
   result->nxt = SortedMerge (a, b->nxt);
  }

 return result;
}

void
FrontBackSplit (struct Node *source, struct Node **frontRef,
		struct Node **backRef)
{

 if (source == NULL || source->nxt == NULL)
  {
   *frontRef = source;
   *backRef = NULL;
   return;
  }

 struct Node *slow = source;
 struct Node *fast = source->nxt;


 while (fast != NULL)
  {
   fast = fast->nxt;
   if (fast != NULL)
	{
	 slow = slow->nxt;
	 fast = fast->nxt;
	}
  }
 *frontRef = source;
 *backRef = slow->nxt;
 slow->nxt = NULL;
}

void
MergeSort (struct Node **head)
{

 if (*head == NULL || (*head)->nxt == NULL)
  return;

 struct Node *a;
 struct Node *b;


 FrontBackSplit (*head, &a, &b);


 MergeSort (&a);
 MergeSort (&b);


 *head = SortedMerge (a, b);
}

int
main ()
{
 if (asd == 0)
  {
   printf ("Hello, This is Made by Nama Venkata Vishwak\n");
   printf
	("Please read the instruction generated atcompile time for better experience\n\n");
   asd = 1;
  }
 int a = 10, b, c, ind;
 printf ("1 To get menu bar input\n0 to exit console\n");
 scanf ("%d", &ind);
 if (ind == 1)
  {
   printf
	("Index\n 0 To check weather the list is empty\n 1 To Insert value\n 2 To Delete\n ");
   printf
	("3 To Display\n 4 To Merge and sort\n 5 to exit Console\n");
   scanf ("%d", &a);
   switch (a)
	{
	case 0:
	 {
	  bool x = true;
	  x = EmptyList ();
	  printf ("%s\n", x ? "Empty\n" : "Not Empty\n");
	  main ();
	 }
	 break;
	case 1:
	 {

	  printf
	   ("0 To Insert at end \n 1 To Insert at perticular position\n 2 To Insert after a number \n");
	  int a;
	  scanf ("%d", &a);
	  if (a == 0)
	   Insert ();
	  else if (a == 1)
	   Insertpos ();
	  else
	   Insertnxt ();

	  main ();
	 }
	 break;
	case 2:
	 {
	  if (head == NULL)
	   printf ("List is empty\n");
	  else
	   {
		printf
		 ("\n 0 To delete a preticular value\n 1 To delete at particular position ");
		printf
		 ("\n 2 To delete 1st value\n 3 To Delete Last value\n ");
		scanf ("%d", &b);
		if (b == 0)
		 Deleteval ();

		else if (b == 1)
		 Deletepos ();

		else if (b == 2)
		 Delete1 ();
		else if (b == 3)
		 Deletelast ();
	   }
	  main ();
	 }
	 break;
	case 3:
	 {
	  Display ();
	  main ();
	 }
	 break;
	case 4:
	 {
	  int n, m, o, p;
	  int i, j, k;
	  printf
	      ("\nInsert the number of Linked Lists to be MergeSorted with existing linked List\n");
	      printf(" 0 To merge sort existing List insert \n");
	  scanf ("%d", &n);
	   if(n!=0){
	    for (i = 1; i <= n; i++)
	      {
	  for (i = 1; i <= n; i++)
	   {
		printf
		 ("Insert the num of values to be inserted in list %d\n", i);
		scanf ("%d", &m);
		printf ("Enter %d numbers whith space in between\n", m);
		for (j = 0; j < m; j++)
		 {
		  insert ();
		 }
	   }
	      }
	      }
	  printf ("The Resultof Merge Sort is:\n");
	  MergeSort (&head);
	  Display ();
	  main ();
	 }
	 break;
	default:
	 {
	  printf (" \nCode Ends\nHave a Good Day");
	  return 0;
	 }
	}
  }
 else
  printf (" \nCode Ends\nHave a Good Day....");
 return 0;
}
