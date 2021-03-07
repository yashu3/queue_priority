#include <stdio.h>
#include <stdlib.h>

struct node
{ int info,priority ;
struct node* link;
};
struct node* add_at_beg(struct node* start,int data ,int prior);
struct node* del(struct node* start);
void display(struct node* start);
   struct  node* sorting(struct node* start);

int main()
{  struct node* start=NULL;
int data,prior;
 int i,n;
 while(1)
 {
   printf("1.add\n");
   printf("2.display\n");
   printf("3.delete\n");
   printf("4.quit\n");
   scanf("%d",&n);
   printf("\n\n");
   switch(n)
   {
   case 1: printf("enter data = \n");
          scanf("%d",&data);
       printf("enter Priority = \n");
       scanf("%d",&prior);
       start=add_at_beg(start,data,prior);
       break;
   case 2:
         display(start);
         break;
   case 3:
         start=del(start);
         break;
   case 4:
        exit(1);
        break;

   default:
       printf("enter right choice");
   }
 }
 return 0;
    }
    struct node* add_at_beg(struct node* start,int data,int prior)
    {
  struct node* tmp;
    tmp=(struct node*)malloc(sizeof(struct node));
    tmp->info=data;
    tmp->priority=prior;
    tmp->link=start;
    start=tmp;
    return start;
    }
   void display(struct node* start)
   {
    struct node *p;
    p= start;
    while(p!=NULL)
    {
    printf("Info=%d\t",p->info);
    printf("Priority=%d\n",p->priority);
    p=p->link;
    }
   }

  struct node* del(struct node* start)
   {
     struct node *prev,*tmp;
     tmp=start;
     start=sorting(start);

     if(tmp==NULL)
      printf("underflow\n");
      else
      {
      while(tmp->link!=NULL)
      { prev=tmp;
      tmp=tmp->link;}
      if(tmp==start)
      {start=NULL;
      free(tmp);}
      else
     { prev->link=NULL;
     free(tmp);
     }

      }


      return start;

   }

   struct  node* sorting(struct node* start)
{
struct node *p,*tmp,*ptr;
int a,n,i,b;
p=start;
tmp=p;
p=p->link;
while(p!=NULL)
{
if(tmp->priority<p->priority)
{ a=tmp->priority;
tmp->priority=p->priority;
p->priority=a;
b=tmp->info;
tmp->info=p->info;
p->info=b;
}
else
{
p=p->link;
tmp=tmp->link;}
}
return (start);
}

