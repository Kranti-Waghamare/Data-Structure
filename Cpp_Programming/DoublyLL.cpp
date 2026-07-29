//Doubly linear linked list in C++.

#include<iostream>
using namespace std;

#pragma pack(1)
struct node
{
    int data;
    struct node * next;
    struct node * prev;         //$
};

typedef struct node NODE;
typedef struct node * PNODE;

class DoublyLL
{
    private :
        PNODE first;
        int iCount;

    public :
        DoublyLL();
        void Display();       //always declare the function inside the class.
        int Count();
        void InsertFirst(int iNo);
        void InsertLast(int iNo);
        void InsertAtPos(int iNo, int iPos);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
};

DoublyLL :: DoublyLL()
{
    this->first = NULL;            //always use "this" pointer while making the oop 
    this->iCount = 0;
}

void DoublyLL ::  Display()              //Always function define outside the class.
{
    PNODE temp = NULL;

    temp = this->first;

    cout<<endl<<"NULL <=>";
    while(temp != NULL)
    {
        cout<<" | "<<temp->data<<" | <=> ";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

int DoublyLL ::  Count()
{
    return this->iCount;
}

void DoublyLL ::  InsertFirst(int iNo)
{
    PNODE newn = NULL;

    newn = new NODE;

    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;                //$

    if(this->first == NULL)
    {
        this->first = newn;
    }
    else
    {
        newn->next = this->first;
        this->first->prev = newn;
        this->first = newn;
    }
    
    this->iCount++;
}

void DoublyLL ::  InsertLast(int iNo)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = new NODE;

    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;                //$

    if(this->first == NULL)
    {
        this->first = newn;
    }
    else
    {
        temp = this->first;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;

        newn->prev = temp;             //$
    }
    
    this->iCount++;
}

void DoublyLL ::  InsertAtPos(int iNo, int iPos)
{
    int i = 0;
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = new NODE;

    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;

    if((iPos < 1) || (iPos > iCount + 1))
    {
        cout<<"Invalid Position"<<endl;
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
        temp = this->first;

        for(i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;       //$

        temp->next = newn;
        newn->prev = temp;             //$

        this->iCount++;
    }
}

void DoublyLL ::  DeleteFirst()
{
    if(this->first == NULL)
    {
        return;
    }
    else if(this->first->next == NULL)
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        this->first = this->first->next;
        delete this->first->prev;           //$
        this->first->prev = NULL;                 //$
    }

    this->iCount--;

}

void DoublyLL ::  DeleteLast()
{
    PNODE temp = NULL;

    if(this->first == NULL)
    {
        return;
    }
    else if(this->first->next == NULL)
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        temp = this->first;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
    }

    this->iCount--;
}

void DoublyLL ::  DeleteAtPos(int iPos)
{
    int i = 0;
    PNODE temp = NULL;

    if((iPos < 1) || (iPos > iCount))
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
        temp = this->first;

        for(i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;       //$
        temp->next->prev = temp;       //$
        
        this->iCount--;
    }
}


int main()
{
    DoublyLL dobj;
    int iRet = 0;

    dobj.InsertFirst(51);
    dobj.InsertFirst(21);
    dobj.InsertFirst(11);

    dobj.Display();

    iRet = dobj.Count();

    cout<<"Number of elements are : "<<iRet<<endl;

    dobj.InsertLast(101);
    dobj.InsertLast(111);
    dobj.InsertLast(121);
    dobj.InsertLast(151);

    dobj.Display();

    iRet = dobj.Count();

    cout<<"Number of elements are : "<<iRet<<endl;

    dobj.DeleteFirst();

    dobj.Display();

    iRet = dobj.Count();

    cout<<"Number of elements are : "<<iRet<<endl;

    dobj.DeleteLast();

    dobj.Display();

    iRet = dobj.Count();

    cout<<"Number of elements are : "<<iRet<<endl;

    dobj.InsertAtPos(105,4);

    dobj.Display();

    iRet = dobj.Count();

    cout<<"Number of elements are : "<<iRet<<endl;

    dobj.DeleteAtPos(4);

    dobj.Display();

    iRet = dobj.Count();

    cout<<"Number of elements are : "<<iRet<<endl;

    return 0;
}