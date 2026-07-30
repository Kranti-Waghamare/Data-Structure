#include<stdio.h>
#include<stdlib.h>

#pragma pack(1)
struct node
{
    int data;
    struct node * next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void Push(PPNODE first, int iNo)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = iNo;
    newn->next = NULL;

    newn->next = *first;
    *first = newn;
}

int Pop(PPNODE first)
{
    int iValue = 0;

    PNODE temp = NULL;
    if(*first == NULL)
    {
        printf("Stack is empty\n");
        return -1;
    }
    else
    {
        iValue = (*first)->data;
        temp = *first;

        *first = (*first)->next;

        free(temp);

        return iValue;
    }
}

int Peep(PPNODE first)
{
    int iValue = 0;

    if(*first == NULL)
    {
        printf("stack is empty\n");
        return -1;
    }
    else
    {
        iValue = (*first)->data;

        return iValue;
    }
}

void Display(PNODE first)
{
    PNODE temp = NULL;

    temp = first;

    while(temp != NULL)
    {
        printf(" | %d | \n", temp->data);
        temp = temp->next;
    }

}

int Count(PNODE first)
{
    PNODE temp = NULL;
    int iCount = 0;

    temp = first;

    while(temp != NULL)
    {
        iCount++;
        temp = temp->next;
    }

    return iCount;
}


int main()
{
    PNODE head = NULL;
    int iRet = 0;

    Push(&head, 11);
    Push(&head, 21);
    Push(&head, 51);
    Push(&head, 101);

    Display(head);

    iRet = Count(head);

    printf("Elements of the stack are : %d\n", iRet);

    iRet = Pop(&head);

    printf("Popped element is : %d\n", iRet);

    Display(head);

    iRet = Count(head);

    printf("Elements of the stack are : %d\n", iRet);

    iRet = Peep(&head);

    printf("Peeped element is : %d\n", iRet);

    Display(head);

    iRet = Count(head);

    printf("Elements of the stack are : %d\n", iRet);
    
    return 0;
}