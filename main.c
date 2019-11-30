//authors: Eoghan Campion, Fionn Murray, Ciaran Moroney
//date: 24/11/19
#include<stdio.h>
#include<malloc.h>

struct link{
       int coeff;
       int pow;
       struct link *next;
       };
struct link *poly1=NULL,*poly2=NULL,*poly=NULL;
void createPoly1(struct link *node)
{
    node->coeff = 3;
    node->pow = 0;
    node=node->next;
    node->next=NULL;
    node->coeff = 4;
    node->pow = 2;
    node=node->next;
    node->next=NULL;
    node->coeff = 6;
    node->pow = 5;
    node=node->next;
    node->next=NULL;
    node->coeff = 7;
    node->pow = 8;

    return poly1;
}

void createPoly2(struct link *node)
{
    node->coeff = 4;
    node->pow = 1;
    node=node->next;
    node->next=NULL;
    node->coeff = 5;
    node->pow = 3;
    node=node->next;
    node->next=NULL;
    node->coeff = 1;
    node->pow = 4;
    node=node->next;
    node->next=NULL;
    node->coeff = 3;
    node->pow = 6;

    return poly2;
}


void show(struct link *node)
{
 while(node->next!=NULL)
 {
  printf("%dx^%d",node->coeff,node->pow);
  node=node->next;
  if(node->next!=NULL)
   printf("+");
 }
}
void addPoly(struct link *poly1,struct link *poly2,struct link *poly)
{
     while(poly1->next &&  poly2->next)
     {
      if(poly1->pow>poly2->pow)
      {
       poly->pow=poly1->pow;
       poly->coeff=poly1->coeff;
       poly1=poly1->next;
       }
      else if(poly1->pow<poly2->pow)
      {
       poly->pow=poly2->pow;
       poly->coeff=poly2->coeff;
       poly2=poly2->next;
       }
      else
      {
       poly->pow=poly1->pow;
       poly->coeff=poly1->coeff+poly2->coeff;
       poly1=poly1->next;
       poly2=poly2->next;
       }
      poly->next=(struct link *)malloc(sizeof(struct link));
      poly=poly->next;
      poly->next=NULL;
     }
     while(poly1->next || poly2->next)
     {
      if(poly1->next)
      {
       poly->pow=poly1->pow;
       poly->coeff=poly1->coeff;
       poly1=poly1->next;
       }
      if(poly2->next)
      {
       poly->pow=poly2->pow;
       poly->coeff=poly2->coeff;
       poly2=poly2->next;
       }
       poly->next=(struct link *)malloc(sizeof(struct link));
       poly=poly->next;
       poly->next=NULL;
       }
}
int main()
{

    poly1=(struct link *)malloc(sizeof(struct link));
    poly2=(struct link *)malloc(sizeof(struct link));
    poly=(struct link *)malloc(sizeof(struct link));

    createPoly1(poly1);
    printf("\nPolynomial 2 is ");
    show(poly1);
    createPoly2(poly2);
    printf("\nPolynomial 2 is ");
    show(poly2);

    addPoly(poly1,poly2,poly);
    printf("\nAdded polynomial:");
    show(poly);
//      printf("\nWanna see me do it again?(y/n): ");
//      cont=getch();
//      }
//      while(cont=='y' || cont=='Y');
