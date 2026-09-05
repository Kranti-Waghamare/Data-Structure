#include<iostream>
using namespace std;

#pragma pack(1)
template<class T>
struct node
{
    T data;
    struct node<T> * next;
};

template<class T>
class DoublyLL
{
    private : 
        struct node<T>  * first;
        struct node<T>  * last;
        int iCount;

    public :
        DoublyLL();
        
        void Display();
        int Count();

        void InsertFirst(T iNo);
        void InsertLast(T iNo);
        void InsertAtPos(T iNo, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
};

template<class T>
DoublyLL<T> :: DoublyLL()
{
    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}

template<class T>
void DoublyLL<T> :: Display()
{
    struct node<T> * temp = NULL;

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

template<class T>
int DoublyLL<T> :: Count()
{
    return this->iCount;
}

template<class T>
void DoublyLL<T> :: InsertFirst(T iNo)
{
    struct node<T> * newn = NULL;
    
    newn = new struct node<T>;

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

template<class T>
void DoublyLL<T> :: InsertLast(T iNo)
{
    struct node<T> * newn = NULL;
    
    newn = new struct node<T>;

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

template<class T>
void DoublyLL<T> :: InsertAtPos(T iNo, int iPos)
{
    int i = 0;
    int iCount = 0;
    struct node<T> * temp = NULL;
    struct node<T> * newn = NULL;

    newn = new struct node<T>;

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

template<class T>
void DoublyLL<T> :: DeleteFirst()
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

template<class T>
void DoublyLL<T> :: DeleteLast()
{
    struct node<T> * temp = NULL;

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

template<class T>
void DoublyLL<T> :: DeleteAtPos(int iPos)
{
    int i = 0;
    int iCount = 0;
    struct node<T> * temp = NULL;
    struct node<T> * target = NULL;

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
    DoublyLL<int> dobj;
    int iRet = 0;

    dobj.InsertFirst(51);
    dobj.InsertFirst(21);
    dobj.InsertFirst(11);

    dobj.InsertLast(101);
    dobj.InsertLast(111);
    dobj.InsertLast(121);

    dobj.Display();

    iRet = dobj.Count();

    cout<<"Number of nodes are : "<<iRet<<endl;

    dobj.DeleteFirst();

    dobj.Display();

    iRet = dobj.Count();

    cout<<"Number of nodes are : "<<iRet<<endl;

    dobj.DeleteLast();

    dobj.Display();

    iRet = dobj.Count();

    cout<<"Number of nodes are : "<<iRet<<endl;

    dobj.InsertAtPos(105, 2);

    dobj.Display();

    iRet = dobj.Count();

    cout<<"Number of nodes are : "<<iRet<<endl;

    dobj.DeleteAtPos(2);

    dobj.Display();

    iRet = dobj.Count();

    cout<<"Number of nodes are : "<<iRet<<endl;

    return 0;
}