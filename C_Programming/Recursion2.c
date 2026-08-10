#include<stdio.h>

//Infinite Recursion
void Display()
{
    printf("Jay Ganesh...\n");

    Display();
}

int main()
{
    Display();
   
    return 0;
}