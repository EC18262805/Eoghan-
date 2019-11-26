#include <stdlib.h>
#include <stdio.h>

struct polly
{
int coeff;
int expo;
};

int addPoly(struct poly pa1[10], struct poly pa2[10], int t1, int t2, struct poly pa[10])
{

    printf("select the two polynomials you want added togrther\nselect the first polynomial");

    int i=0;
    int j=0;
    int k=0;

    while(i<t1 && j<t2)
    {
        if(pa1[i].expo==pa2[j].expo)
        {
            pa[k].coeff=pa1[i].coeff + pa2[j].coeff;
            pa[k].expo=pa1[i].expo;

            i++;
            j++;
            k++;
        }
        else if(pa1[i].expo>pa2[j].expo)
        {
            pa[k].coeff=pa1[i].coeff;
            pa[k].expo=pa1[i].expo;
            i++;
            k++;
        }
        else
        {
        pa[k].coeff=pa2[j].coeff;
        pa[k].expo=pa2[j].expo;
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
