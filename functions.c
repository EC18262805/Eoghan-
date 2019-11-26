#include <stdlib.h>
#include <stdio.h>

struct polly
{
int coeff;
};

int addPoly(struct poly pa1[10], struct poly pa2[10], int t1, int t2, struct poly pa[10])
{
    int choice1;
    int choice2;
    printf("select the two polynomials you want added togrther\nselect the first polynomial");
    sacnf("%d", &choice1);
    printf("select the second polynomial\n");
    scanf("%d", &choice2);
    
    //pa(choice1)[]==pa1[];
    //pa(choice2)[]==pa2[];
    
    int i=0;
    int j=0;
    int k=0;

    while(i<t1 && j<t2)
    {
        if(pa1[i].expo==pa2[j].expo)
        {
            pa[k].coeff=pa1[i].coeff + pa2[j].coeff;

            i++;
            j++;
            k++;
        }
        else if(pa1[i].expo>pa2[j].expo)
        {
            pa[k].coeff=pa1[i].coeff;
            i++;
            k++;
        }
        else
        {
        pa[k].coeff=pa2[j].coeff;
        j++;
        k++;
        }
    }
    while(i<t1)
    {
        pa[k].coeff=pa1[i].coeff;
        pa[k].coeff=pa1[i].expo;
        i++;
        k++;
    }
    while(j<t2)
    {
        pa[k].coeff=pa2[j].coeff;
        pa[k].coeff=pa2[j].expo;
        j++;
        k++;
    }

    return(k);

}


int readPoly(struct poly p[10])
{
    int t1,i;

    printf("Highest Degree of the Polynomial: \n");
    scanf("%d", &t1);

    printf("Enter the Coefficients in Ascending order\n");
    for(i=0;i<t1;i++)
    {
        printf("Enter the Coefficient(x^%d):\n", i);
        scanf("%d", &p[i].coeff);
        //printf("Enter the coresponding exponent(%d):",i+1);
        //scanf("%d,&p[i].exponent);
    }
    return t1;
}

void displayPoly(struct poly p[10], int term)
{
    int k;

    for(k=0;k<term-1;k++)
    if(p[k].coeff==0)
    printf("%d(x^%d)+", p[k].coeff, k);
    printf("%d(x^%d)", p[term-1].coeff,k);
}
