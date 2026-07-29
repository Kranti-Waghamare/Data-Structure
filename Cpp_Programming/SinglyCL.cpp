// singly circular linked list in cpp.

#include<iostream>
using namespace std;

#pragma pack(1)
struct node
{
    int data;
    struct node * next;
};

typedef struct node NODE;
typedef struct node * PNODE;

class SinglyCL
{
    private : 
        PNODE first;
        PNODE last;
        int iCount;

    public :
        SinglyCL();
        
        void Display();
        int Count();

        void InsertFirst(int iNo);
        void InsertLast(int iNo);
        void InsertAtPos(int iNo, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
};

SinglyCL :: SinglyCL()
{
    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}

void SinglyCL :: Display()
{
    PNODE temp = NULL;

    if(this->first == NULL && this->last == NULL)
    {
        return;
    }

    temp = this->first;

    do
    {
        cout<<" | "<<temp->data<<" | ->";
        temp = temp->next;
    } while (this->last->next != temp);

    cout<<"\n";
    
}

int SinglyCL :: Count()
{
    return this->iCount;
}

void SinglyCL :: InsertFirst(int iNo)
{
    PNODE newn = NULL;
    
    newn = new NODE;

    newn->data = iNo;
    newn->next = NULL;

    if(this->first == NULL && this->last == NULL)
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        newn->next = this->first;
        this->first = newn;
    }
    this->last->next = this->first;
    this->iCount++;
}

void SinglyCL :: InsertLast(int iNo)
{
    PNODE newn = NULL;
    
    newn = new NODE;

    newn->data = iNo;
    newn->next = NULL;

    if(this->first == NULL && this->last == NULL)
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        this->last->next= newn;
        this->last = newn;
    }
    this->last->next = this->first;
    this->iCount++;
}

void SinglyCL :: InsertAtPos(int iNo, int iPos)
{
    int i = 0;
    int iCount = 0;
    PNODE temp = NULL;
    PNODE newn = NULL;

    newn = new NODE;

    newn->data = iNo;
    newn->next = NULL;

    iCount = Count();

    if((iPos < 1) || (iPos > iCount + 1))
    {
        cout<<"Invalid Position"<<endl;
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(iNo);
    }
    else if(iPos > iCount + 1)
    {
        InsertLast(iNo);
    }
    else
    {
        temp = this->first;

        for(i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;
    }
    this->iCount++;
}

void SinglyCL :: DeleteFirst()
{
    if(this->first == NULL && this->last == NULL)
    {
        return;
    }
    else if(this->first == this->last)
    {
        delete this->first;
        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        this->first = this->first->next;
        delete this->last->next;
        this->last->next = this->first;
    }
    this->iCount--;
}

void SinglyCL :: DeleteLast()
{
    PNODE temp = NULL;

    if(this->first == NULL && this->last == NULL)
    {
        return;
    }
    else if(this->first == this->last)
    {
        delete this->first;
        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        temp = this->first;

        while(temp->next != this->last)
        {
            temp = temp->next;
        }

        delete this->last;
        this->last = temp;
        this->last->next = this->first;
    }
    this->iCount--;
}

void SinglyCL :: DeleteAtPos(int iPos)
{
    int i = 0;
    int iCount = 0;
    PNODE temp = NULL;
    PNODE target = NULL;

    iCount = Count();

    if((iPos < 1) || (iPos > iCount))
    {
        cout<<"Invalid Position"<<endl;
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos > iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = this->first;

        for(i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }
        target = temp->next;

        temp->next = target->next;

        delete target;

    }
    this->iCount--;
}

int main()
{
    SinglyCL sobj;
    int iRet = 0;

    sobj.InsertFirst(51);
    sobj.InsertFirst(21);
    sobj.InsertFirst(11);

    sobj.InsertLast(101);
    sobj.InsertLast(111);
    sobj.InsertLast(121);

    sobj.Display();

    iRet = sobj.Count();

    cout<<"Number of nodes are : "<<iRet<<endl;

    sobj.DeleteFirst();

    sobj.Display();

    iRet = sobj.Count();

    cout<<"Number of nodes are : "<<iRet<<endl;

    sobj.DeleteLast();

    sobj.Display();

    iRet = sobj.Count();

    cout<<"Number of nodes are : "<<iRet<<endl;

    sobj.InsertAtPos(105, 2);

    sobj.Display();

    iRet = sobj.Count();

    cout<<"Number of nodes are : "<<iRet<<endl;

    sobj.DeleteAtPos(2);

    sobj.Display();

    iRet = sobj.Count();

    cout<<"Number of nodes are : "<<iRet<<endl;

    return 0;
}