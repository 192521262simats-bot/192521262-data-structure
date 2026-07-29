#include <stdio.h>

int main()
{
    int stack[20];
    int top = -1;

   
    stack[++top] = 8;
    stack[++top] = 2;
    int a = stack[top--];
    int b = stack[top--];
    stack[++top] = b + a;     

   
    stack[++top] = 6;
    stack[++top] = 4;
    a = stack[top--];
    b = stack[top--];
    stack[++top] = b - a;      

    
    a = stack[top--];
    b = stack[top--];
    stack[++top] = b * a;     

    
    stack[++top] = 2;
    a = stack[top--];
    b = stack[top--];
    stack[++top] = b / a;     

    printf("Expression : (8+2)*(6-4)/2\n");
    printf("Result = %d\n", stack[top]);

    return 0;
}