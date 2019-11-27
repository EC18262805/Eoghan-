//program to store and calculate the addition/subteraction
//and the mulitpication/devison of polynominals
//author: Eoghan Campion, Fionn Murray, Ciran Moroney
//date: 24/11/19

#include <stdio.h>
#include <stdlib.h>

#include "functions.c"
#include "decleration.h"

struct polly
{
int coeff;
}

struct poly p1[10],p2[10],p3[10],p4[10],p5[10],p6[10],p7[10],p8[10],p9[10],pa[10];

double main()
{

    int loop = 0;

    do
    {
        printf("Hi, Welcome to plooynomial-mania a program by Eoghan, Fionn, Ciran\n") +
        ("What action would you like to take. Please enter a number");
        printf("1. Create a poly\n");
        printf("2. Delete a poly\n");
        printf("3. Add 2 polys\n");
        printf("4. subtract 2 polys\n");
        printf("5. Multiply 2 polys\n");
        printf("6. Divide one poly bu another\n");
        printf("7. Return order of a polynomial");
        printf("8. Normalise polynomial");
        printf("9. Print polynomial");
        printf("10. Display all stored polynomials");

        int choice;
        scanf("%d",&choice);
        switch(choice)
            {
            case 1:
                createpoly();
            break;

            case 2:
                delPoly();
            break;

            case 3:
                addPoly();
            break;

            case 4:
                minusPoly();
            break;

            case 5:
                mulPoly();
            break;

            case 6:
                divPoly();
            break;

            case 7:
                ReOrderPoly();
            break;

            case 8:
                normalPoly();
            break;

            case 9:
                printPoly();
            break;

            case 10:
                displayPoly();
            break;

            case 11:
                testPoly();
            break;

            default:
                printf("invalid input\n");
            break;

            }

        printf("Are you finished with the program, type 1 for yes and 0 for no");
        scanf("%d", &loop)

        }while(loop == 1);

}
