void mulPoly(struct link *polyMul, struct link *poly1,struct link *node)
{
    double mul = 4;

    while(node->next!= NULL)
        {
            polyMul->next = (struct link *)malloc(sizeof(struct link));
            polyMul->coeff = (poly1->coeff*mul);
            polyMul->pow=poly1->pow;
            polyMul=polyMul->next;
            polyMul->next=NULL;
        }
}
