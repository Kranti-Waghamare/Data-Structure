//Doubly Circular in C++

#include<iostream>
using namespace std;

#pragma pack(1)
struct node
{
    int data;
    struct node * next;
    struct node * prev;;
};

typedef struct node NODE;
typedef struct node * PNODE;

#pragma pack(1)
class DoublyCL
{
    private :
        PNODE first;
        PNODE last;
        int iCount;

    public :
        DoublyCL();

        void Display();
        int Count();

        void InsertFirst(int iNo);
        void InsertLast(int iNo);
        void InsertAtPos(int iNo, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
};

DoublyCL :: DoublyCL()
{
    first = NULL;
    last = NULL;
    iCount = 0;
}

void DoublyCL :: Display()
{
    PNODE temp = NULL;
    temp = first;

    if(first == NULL && last == NULL)
    {
        return;
    }

    cout<<" <=> "<<endl;

    do
    {
        cout<<" | "<<temp->data<<" | <=>";
        temp = temp->next;
    } while (temp != last->next);
    
    cout<<endl;
}

int DoublyCL :: Count()
{
    PNODE temp = NULL;
    temp = first;

    int iCount = 0;

    if(first == NULL && last == NULL)
    {
        return iCount;
    }

    do
    {
        iCount++;
        temp = temp->next;
    }while(temp != last->next);

    return iCount;
}

void DoublyCL :: InsertFirst(int iNo)
{
    PNODE newn = NULL;

    newn = new NODE;

    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL && last == NULL)
    {
        first = newn;
        last = newn;
    }
    else 
    {
        newn->next = first;
        first->prev = newn;
        newn->prev = last;
        last->next = newn;
        first = newn;
    }
    last->next = first;
    first->prev = last;

    iCount++;
}

void DoublyCL :: InsertLast(int iNo)
{
    PNODE newn = NULL;

    newn = new NODE;

    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL && last == NULL)
    {
        first = newn;
        last = newn;
        newn->next = newn;
        newn->prev = newn;
    }
    else
    {
       newn->prev = last;
       last->next = newn;
       newn->next = first;
       first->prev = newn;
       last = newn;
    }

    last->next = first;
    first->prev = last;
    iCount++;    
}

void DoublyCL :: InsertAtPos(int iNo, int iPos)
{
    int i = 0;

    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = new NODE;

    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;

    if((iPos < 1)||(iPos > iCount + 1))
    {
        cout<<"Invalid position"<<endl;
        return;
    }
   
    if(iPos == 1)
    {
        InsertFirst(iNo);
    }
    else if(iPos == iCount + 1)
    {
        InsertLast(iNo);
    }
    else 
    {
        temp = first;

        for(i = 1; i < iPos -1; i++)
        {
            temp = temp->next;
        }

        newn->next= temp->next;
        newn->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;
        iCount++;
    }
}

void DoublyCL :: DeleteFirst()
{
    if(first == NULL && last == NULL)
    {
        return;
    }
    else if(first == last)
    {
        free(first);
        first = NULL;
        last = NULL;
    }
    else
    {
        first = first->next;
        delete last->next;

        last->next = first;
        first->prev = last;
    }
    iCount--;
}

void DoublyCL :: DeleteLast()
{
    PNODE temp = NULL;

    if(first == NULL && last == NULL)
    {
        return;
    }
    else if(first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else 
    {
        temp = last;

        last = last->prev;
        delete temp;

        last->next = first;
        first->prev = last;
    }
    iCount--;
}

void DoublyCL :: DeleteAtPos(int iPos)
{
    int i = 0;
    PNODE temp = NULL;

    if((iPos < 1)||(iPos > iCount))
    {
        cout<<"Invalid Position"<<endl;
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = first;
        for(i = 1; i < iPos; i++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        iCount--;
    }
}


int main()
{
    DoublyCL dobj;
    int iRet = 0;

    dobj.InsertFirst(51);
    dobj.InsertFirst(21);
    dobj.InsertFirst(11);

    dobj.InsertLast(101);
    dobj.InsertLast(111);
    dobj.InsertLast(121);

    dobj.Display();

    iRet = dobj.Count();

    cout<<"Number of nodes are : "<< iRet<<endl;

    dobj.DeleteFirst();

    dobj.Display();

    iRet = dobj.Count();

    cout<<"Number of nodes are : "<<iRet<<endl;
    
    dobj.DeleteLast();

    dobj.Display();

    iRet = dobj.Count();

    cout<<"Number of nodes are : "<<iRet<<endl;

    dobj.InsertAtPos(90, 3);

    dobj.Display();

    iRet = dobj.Count();

    cout<<"Number of nodes are : "<<iRet<<endl;

    dobj.DeleteAtPos(3);

    dobj.Display();

    iRet = dobj.Count();

    cout<<"Number of nodes are : "<<iRet<<endl;

    return 0;
}