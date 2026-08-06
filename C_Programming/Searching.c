//Searching in C

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void Accept(int Arr[], int iSize)
{
    int i = 0;

    printf("Enter the elements : \n");

    for(i = 0; i < iSize; i++)
    {
        scanf("%d", &Arr[i]);
    }
}

void Display(int Arr[], int iSize)
{
    int i = 0;

    printf("Elements of the array are : \n");

    for(i = 0; i < iSize; i++)
    {
        printf("%d\n",Arr[i]);
    }

}

bool LinearSearch(int Arr[], int iSize, int iNo)
{
    bool bFlag = false;
    int i = 0;

    for(i = 0; i < iSize; i++)
    {
        if(iNo == Arr[i])
        {
            bFlag = true;
            break;
        }

    }

    return bFlag;
}

bool BiDirectionalSearch(int Arr[], int iSize, int iNo)
{
    bool bFlag = false;
    int iStart = 0;
    int iEnd = 0;

    iStart = 0;
    iEnd = iSize - 1;

    while (iStart <= iEnd)
    {
        if((Arr[iStart] == iNo) || (Arr[iEnd] == iNo))
        {
            bFlag = true;

            break;
        }

        iStart++;
        iEnd--;
    }

    return bFlag;
    
}

int main()
{
    int * ptr = NULL;
    int iLength = 0;
    int iValue = 0;

    printf("Enter the number of elements : \n");
    scanf("%d", &iLength);

    if(iLength < 0)
    {
        iLength = -iLength;
    }

    ptr = (int *)malloc(sizeof(int) * iLength);

    if(ptr == NULL)
    {
    printf("Unable to allocate memory\n");
    return -1;
    }

    Accept(ptr, iLength);

    Display(ptr, iLength);

    printf("Enter the element to search : \n");
    scanf("%d", &iValue);

    if(LinearSearch(ptr, iLength, iValue) == true)
    {
        printf("Element is present\n");
    }
    else
    {
        printf("There is no such element\n");
    }

    if(BiDirectionalSearch(ptr, iLength, iValue) == true)
    {
        printf("Element is present\n");
    }
    else
    {
        printf("Element is not present\n");
    }

    free(ptr);

    return 0;
}