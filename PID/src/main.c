#include <stdio.h>
#include <stdlib.h>
#include "../headers/function.h"
#include "../headers/structs.h"
#include "../headers/macros.h"

int main()
{
    /*-----------------For Test---------------------
    printf("Hello world!\n");
    printf("Hello git!\n");
    int a[]={1,2,1,2,1,2,1};
    char b[]={'w','e','w','q'};
    int *c[1];
    c[0]=a;
    printf("%d\n",sizeof(b));
    printf("%d\n",c[0][3]);
    ----------------------------------------*/
    float a[3]={2,5,6};
    Rotate_1D_Array(a,3,8);
    unsigned int i=0;
    while(i<sizeof(a)/4)
        printf("%f\n",a[(++i)-1]);
        i=0;
    Rotate_1D_Array(a,3,8);
    while(i<sizeof(a)/4)
        printf("%f\n",a[(++i)-1]);
        i=0;
    Rotate_1D_Array(a,3,8);
    while(i<sizeof(a)/4)
        printf("%f\n",a[(++i)-1]);

    return 0;
}
