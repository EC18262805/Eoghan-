//authors: Eoghan Campion, Fionn Murray, Ciaran Moroney
//date: 24/11/19
#include<stdio.h>
#include<malloc.h>

struct link{
       int coeff;
       int pow;
       struct link *next;
       };


struct link *poly1=NULL,*poly2=NULL,*polyAdd=NULL, *polyMul=NULL, *polyMulCorrect=NULL;

void mulPoly(struct link *polyMul, struct link *poly1);
void createPolyMulCorrect(struct link *node);
void testMulpoly();

void createPoly1(struct link *node)
{

    node->coeff =3;
    node->pow = 0;
    node->next=(struct link *)malloc(sizeof(struct link));
    node=node->next;
    node->next=NULL;
    node->coeff = 4;
    node->pow = 3;
    node->next=(struct link *)malloc(sizeof(struct link));
    node=node->next;
    node->next=NULL;
    node->coeff = 6;
    node->pow = 5;
    node->next=(struct link *)malloc(sizeof(struct link));
    node=node->next;
    node->next=NULL;
    node->coeff = 7;
    node->pow = 8;
    node->next=(struct link *)malloc(sizeof(struct link));
    node=node->next;
    node->next=NULL;
}

void createPoly2(struct link *node)
{
    node->coeff = 4;
    node->pow = 1;
    node->next=(struct link *)malloc(sizeof(struct link));
    node=node->next;
    node->next=NULL;
    node->coeff = 5;
    node->pow = 3;
    node->next=(struct link *)malloc(sizeof(struct link));
    node=node->next;
    node->next=NULL;
    node->coeff = 1;
    node->pow = 4;
    node->next=(struct link *)malloc(sizeof(struct link));
    node=node->next;
    node->next=NULL;
    node->coeff = 3;
    node->pow = 6;
    node->next=(struct link *)malloc(sizeof(struct link));
    node=node->next;
    node->next=NULL;
}


void show(struct link *node)
{
 while(node->next!=NULL)
 {
  printf("%dx^%d",node->coeff,node->pow);
  node=node->next;
  if(node->next!=NULL)
   printf(" + ");
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


    poly2=(struct link *)malloc(sizeof(struct link));
    poly1=(struct link *)malloc(sizeof(struct link));
    polyMul=(struct link *)malloc(sizeof(struct link));
    polyMulCorrect=(struct link *)malloc(sizeof(struct link));

    createPoly1(poly1);
    printf("\n\nFirst polynomial:");
    show(poly1);

    createPoly2(poly2);
    printf("\n\nSecond polynomial:");
    show(poly2);

    mulPoly(poly1,polyMul);
    printf("\n\nmultiplied Polynomial:");
    show(polyMul);

    createPolyMulCorrect(polyMulCorrect);
    printf("\n\nCorrect Answer:");
    show(polyMulCorrect);

    if(polyMul->coeff==polyMulCorrect->coeff && polyMul->pow==polyMulCorrect->pow)
    {
        printf("\n\nTest Passed");
    }
    else
    {
        printf("\n\nTest Failed");
    }
}


void mulPoly(struct link *polyMul, struct link *poly1)
{
    double mul = 4;
    double temp;
    int temp2;

    while(poly1->next)
        {
        temp = poly1->coeff*mul;
        temp2 = poly1->pow;

        polyMul->coeff = temp;
        polyMul->pow = temp2;

        polyMul->next = (struct link*)malloc(sizeof(struct link));
        polyMul=polyMul->next;
        }

}

void createPolyMulCorrect(struct link *node)
{
    node->coeff = 12;
    node->pow = 0;
    node->next=(struct link *)malloc(sizeof(struct link));
    node=node->next;
    node->next=NULL;
    node->coeff = 16;
    node->pow = 3;
    node->next=(struct link *)malloc(sizeof(struct link));
    node=node->next;
    node->next=NULL;
    node->coeff = 24;
    node->pow = 5;
    node->next=(struct link *)malloc(sizeof(struct link));
    node=node->next;
    node->next=NULL;
    node->coeff = 28;
    node->pow = 8;
    node->next=(struct link *)malloc(sizeof(struct link));
    node=node->next;
    node->next=NULL;
}

//void testMulpoly()
//{
//    poly1=(struct link *)malloc(sizeof(struct link));
//    polyMul=(struct link *)malloc(sizeof(struct link));
//    polyMulCorrect=(struct link *)malloc(sizeof(struct link));
//
//    createPoly1(poly1);
//    printf("\nFirst polynomial:");
//    show(poly1);
//
//    createPoly2(poly2);
//    printf("\nSecond polynomial:");
//    show(poly2);
//
//    mulPoly(poly1,polyMul);
//    printf("\nmultiplied Polynomial:");
//    show(polyMul);
//
//    createPolyMulCorrect(polyMulCorrect);
//    printf("\nCorrect Answer:");
//    show(polyMulCorrect);
//
//    if(polyMul->coeff==polyMulCorrect->coeff && polyMul->pow==polyMulCorrect->pow)
//    {
//        printf("\nTest Passed");
//    }
//    else
//    {
//        printf("\nTest Failed");
//    }
//
//}

//void divPolyt1(struct link *node, struct link *poly1)
//{
//    int div = 4;
//
//    while(node->next!=NULL)
//        {
//            node->coeff = (node->coeff)/(div);
//        }
//}
//
//void normalPolyt1(struct link *node, struct link *poly2)
//{
//
//
//
//
//
//}









