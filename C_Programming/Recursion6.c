#include<stdio.h>

//Recursion
void Display()
{
    auto int i = 0;

    i = 1;

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