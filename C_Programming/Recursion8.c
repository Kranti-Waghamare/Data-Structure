#include<stdio.h>

//Recursion
void Display()
{
    static int i = 0;

    if(i <= 4)
    {
        printf("Jay Ganesh...%d\n", i);
        i++;
        Display();
    }
}

int main()
{
    Display();
   
    return 0;
}