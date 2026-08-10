#include<stdio.h>

//Recursion
void Display(int iNo)
{

    if(iNo != 0)
    {
        printf("Jay Ganesh...%d\n", iNo);
        Display(iNo--);
    }
}

int main()
{
    int iValue = 0;

    printf("Enter the Number : \n");
    scanf("%d", &iValue);

    Display(iValue);
   
    return 0;
}