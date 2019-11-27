/*


*/
mulPoly()
{
    double  mul;
    printf("Type the vaule you want the polynomial multipied by\n");
    scanf("%lf", &mul);

    for(int i=0;i<maxOrder;i++)
    {
    p[i].coeff=mul*p[i].ceoff;
    }

}

divPoly()
{
    double  div;
    printf("Type the vaule you want the polynomial divided by\n");
    scanf("%lf", &div);

    for(int i=0;i<maxOrder;i++)
    {
    p[i].coeff=(p[i].ceoff)/(div);
    }

}

normPoly()
{
int norm = p[maxOrder].coeff;
    for(int i=0;i<maxOrder;i++)
    {
    p[i].coeff=()p[i].ceoff)/(norm);
    }
}
