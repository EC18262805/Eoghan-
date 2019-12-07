//authors: Eoghan Campion, Fionn Murray, Ciaran Moroney
//date: 24/11/19
#include<stdio.h>
#include<malloc.h>

struct link{
       double coeff;
       int pow;
       struct link *next;
       };


struct link *poly2=NULL,*polyDiv=NULL, *polyDivCorrect=NULL;

void divPoly(struct link *polyDiv, struct link *poly1);
void createPolyDivCorrect(struct link *node);
void display(struct link *node);

void createPoly2(struct link *node)
{

    node->coeff =4;
    node->pow = 0;
    node->next=(struct link *)malloc(sizeof(struct link));
    node=node->next;
    node->next=NULL;
    node->coeff = 5;
    node->pow = 1;
    node->next=(struct link *)malloc(sizeof(struct link));
    node=node->next;
    node->next=NULL;
    node->coeff = 1;
    node->pow = 2;
    node->next=(struct link *)malloc(sizeof(struct link));
    node=node->next;
    node->next=NULL;
    node->coeff = 2;
    node->pow = 3;
    node->next=(struct link *)malloc(sizeof(struct link));
    node=node->next;
    node->next=NULL;
}



void display(struct link *node)
{
 while(node->next!=NULL)
 {
  printf("%fx^%d",node->coeff,node->pow);
  node=node->next;
  if(node->next!=NULL)
   printf(" + ");
 }
}

int main()
{

    poly2=(struct link *)malloc(sizeof(struct link));
    polyDiv=(struct link *)malloc(sizeof(struct link));
    polyDivCorrect=(struct link *)malloc(sizeof(struct link));

    createPoly2(poly2);
    printf("\n\nFirst polynomial:");
    display(poly2);

    divPoly(polyDiv,poly2);
    printf("\n\nmultiplied Polynomial:");
    display(polyDiv);

    createPolyDivCorrect(polyDivCorrect);
    printf("\n\nCorrect Answer:");
    display(polyDivCorrect);

    if(polyDiv->coeff==polyDivCorrect->coeff && polyDiv->pow==polyDivCorrect->pow)
    {
        printf("\n\nTest Passed");
    }
    else
    {
        printf("\n\nTest Failed");
    }
}


void divPoly(struct link *poly2, struct link *polyDiv)
{
    double div = 2;
    double temp;
    int temp2;

    while(poly2->next)
        {
        temp = poly2->coeff/div;
        temp2 = poly2->pow;

        poly2=poly2->next;

        polyDiv->coeff = temp;
        polyDiv->pow = temp2;

        polyDiv->next = (struct link*)malloc(sizeof(struct link));
        polyDiv=polyDiv->next;
        polyDiv->next = NULL;

        }

}

void createPolyDivCorrect(struct link *node)
{
    node->coeff = 2;
    node->pow = 0;
    node->next=(struct link *)malloc(sizeof(struct link));
    node=node->next;
    node->next=NULL;
    node->coeff = 2.5;
    node->pow = 1;
    node->next=(struct link *)malloc(sizeof(struct link));
    node=node->next;
    node->next=NULL;
    node->coeff = 0.5;
    node->pow = 2;
    node->next=(struct link *)malloc(sizeof(struct link));
    node=node->next;
    node->next=NULL;
    node->coeff = 1.5;
    node->pow = 3;
    node->next=(struct link *)malloc(sizeof(struct link));
    node=node->next;
    node->next=NULL;
}
