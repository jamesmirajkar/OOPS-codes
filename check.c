// A simple C program to demonstrate callback
#include <stdio.h>
extern int var;
void A(int a)
{
    printf("I am function A\n");
}

// callback function
void B()
{
    printf("I am function B\n");
}
void C(void (*ptr)(int))
{
    (*ptr)(10); // callback to A
}
int main()
{

    // calling function B and passing
    // address of the function A as argument
    void (*ptr)(int) = &A;

    (*ptr)(10);

    C(A);

    C(B);

    int *p;
    int a =10;
    p =&a;

    printf("%d",sizeof(p));
    int var = 10;
    return 0;
}
