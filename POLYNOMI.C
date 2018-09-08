/* Creating Polynomial and Perform Several Operations */
#include <stdio.h>
#include <conio.h>
#include <alloc.h>
struct poly
{
 int coff;
 int deg;
 struct poly *next;
};
////////////////
void menu()
{
 printf("\n\t* * * * MAIN MENU * * * *\n");
 printf("\n\t1.Create 1st Polynomial");
 printf("\n\t2.Create 2nd Polynomial");
 printf("\n\t3.Display polynomials");
 printf("\n\t4.Add Two Polynomials");
 printf("\n\t5.Multiply Two Polynomials");
 printf("\n\t6.Exit");
}
//////////////////
void boundary()
{
 int i;
 printf("\n\n   ");
 for(i=0;i<16; i++)
 printf("==");
 gotoxy(10,3);
 menu();
 printf("\n    ");
 for(i=0;i<16; i++)
  printf("==");
 getch();
}
/////////////////
void create(struct poly **p, int c, int d)
{
 struct poly *temp=*p;
 if(*p==NULL)
 {
  if(c==0)
  return;
  else
  {
   *p=(struct poly*)malloc(sizeof(struct poly));
   (*p)->coff=c;
   (*p)->deg=d;
   (*p)->next=NULL;
  }
 }
 else
 {
  while(temp->next!=NULL)
  temp=temp->next;
  if(c==0)
   return;
  else
  {
   temp->next=(struct poly *)malloc(sizeof(struct poly));
   temp->next->coff=c;
   temp->next->deg=d;
   temp->next->next=NULL;
  }
 }
}
///////////////////
void display(struct poly *p)
{
 while(p!=NULL)
 {
  printf("%.1dx^%d ",p->coef,p->deg);
  p=p->next;
 }
}
////////////////
void add_poly(struct poly *p1,struct poly *p2,struct poly **r)
{
 struct poly *s;
 while(p1!=NULL && p2!=NULL)
 {
  if(*r==NULL)
  {
   *r=(struct poly *)malloc(sizeof(struct poly));
   s=*r;
  }
  else
  {
   s->next=(struct poly *)malloc(sizeof(struct poly));
   s=s->next;
  }
  if(p1->deg > p2->deg)
  {
   s->coff=p1->coff;
   s->deg=p1->deg;
   p1=p1->next;
  }
  else
  {
   if(p1->deg < p2->deg)
   {
    s->coff=p2->coff;
    s->deg=p2->deg;
    p2=p2->next;
   }
   else
   {
    if(p1->deg==p2->deg)
    {
     s->coff=p1->coff+p2->coff;
     s->deg=p1->deg;
     p1=p1->next;
     p2=p2->next;
    }
   }
  }
 }
 s->next=NULL;
}
////////////////
void poly_add(int c1,int d1,struct poly **z)
{
 struct poly *s, *t=*z;
 if(*z==NULL || d1 > (*z)->deg)
 {
  *z=(struct poly*)malloc(sizeof(struct poly));
  (*z)->coff=c1;
  (*z)->deg=d1;
  s=*z;
  (*z)->next=t;
 }
 else
 {
  while(t!=NULL)
  {
   if(t->deg == d1)
   {
    t->coff=t->coff+c1;
    return;
   }
   if(t->deg > d1 && (t->next->deg < d1 || t->next==NULL))
   {
    s=(struct poly*)malloc(sizeof(struct poly));
    s->coff=c1;
    s->deg=d1;
    s->next=t->next;
    t->next=s;
    return;
   }
   t=t->next;
  }
  s->next=NULL;
  t->next=s;
 }
}
/////////////////////
void mul_poly(struct poly *p1,struct poly *p2,struct poly **r)
{
 struct poly *s;
 int c,d;
  s=p1;
 if(p1==NULL)
  *r=p2;
 else if(p2==NULL)
  *r=p1;
 else
 {
  while(p2!=NULL)
  {
   while(p1!=NULL)
   {
    c=p1->coff*p2->coff;
    d=p1->deg+p2->deg;
    p1=p1->next;
    poly_add(c,d,r);
   }
   p1=s;
   p2=p2->next;
  }
 }
}
////////////////////
void main()
{
 struct poly *head1=NULL,*head2=NULL,*head3=NULL,*head4=NULL;
 int i,c,n,choice,temp1;
 do
 {
  clrscr();
  boundary();
  printf("\n\n\tCHOICE: ");
  scanf("%d",&choice);
  if(choice==1)
  {
   printf("\nEnter degree of 1st polynomial: ");
   scanf("%d",&n);
   for(i=n; i>=0; i--)
   {
    printf("\nEnter coefficient of degree %d: ",i);
    scanf("%d",&c);
    create(&head1,c,i);
   }
  }
  else if(choice==2)
  {
   printf("\nEnter degree of 2nd polynomial: ");
   scanf("%d",&n);
   for(i=n; i>=0; i--)
   {
    printf("\nEnter coefficient of degree %d: ",i);
    scanf("%d",&c);
    create(&head2,c,i);
   }
  }
  else if(choice==3)
  {
   if(head1!=NULL && head2!=NULL)
   {
    printf("\nFirst Polynomial: ");
    display(head1);
    printf("\nSecond Polynomial: ");
    display(head2);
   }
   else
    printf("\nNo Polynomial.");
  }
  else if(choice==4)
  {
   if(head1!=NULL && head2!=NULL)
   {
    add_poly(head1,head2,&head3);
    printf("\nResultant polynomial: ");
    display(head3);
   }
   else
    printf("\nNo Polynomial.");
  }
  else if(choice==5)
  {
   if(head1!=NULL && head2!=NULL)
   {
    mul_poly(head1,head2,&head4);
    printf("\nResultant polynomial: ");
    display(head4);
   }
   else
    printf("\nNo Polynomial.");
  }
  else if(choice==6)
   exit(0);
  else
   printf("\nPlease enter a valid choice.");
  getche();
 }while(choice!=6);
}