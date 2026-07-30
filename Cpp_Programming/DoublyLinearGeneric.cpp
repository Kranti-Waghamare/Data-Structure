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
class SinglyCL
{
    private : 
        struct node<T>  * first;
        struct node<T>  * last;
        int iCount;

    public :
        SinglyCL();
        
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
SinglyCL<T> :: SinglyCL()
{
    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}

template<class T>
void SinglyCL<T> :: Display()
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
int SinglyCL<T> :: Count()
{
    return this->iCount;
}

template<class T>
void SinglyCL<T> :: InsertFirst(T iNo)
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
void SinglyCL<T> :: InsertLast(T iNo)
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
void SinglyCL<T> :: InsertAtPos(T iNo, int iPos)
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
void SinglyCL<T> :: DeleteFirst()
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
void SinglyCL<T> :: DeleteLast()
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
void SinglyCL<T> :: DeleteAtPos(int iPos)
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
    SinglyCL<int> sobj;
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