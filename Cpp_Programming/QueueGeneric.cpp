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
class Queue
{
    private : 
        struct node<T> * first;
        int iCount;

    public :
        Queue();
        void Enqueue(T iNo);         
        T Dequeue();                  
        void Display();
        int Count(); 
};

template<class T>
Queue<T> :: Queue()
{
    this->first = NULL;
    this->iCount = 0;
}

template<class T>
void Queue<T> :: Enqueue(T iNo)   
{
    struct node<T> * newn = NULL;
    struct node<T> * temp = NULL;

    newn = new  struct node<T>();

    newn->data = iNo;
    newn->next = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        temp = first;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
    }

    this->iCount++;
}      

template<class T>
T Queue<T> :: Dequeue()    
{
    T iValue = 0;
    struct node<T> * temp = NULL;

    if(this->first == NULL)
    {
        cout<<"Queue is empty";
        return -1;
    }
    else
    {
        iValue = first->data;
        temp = first;

        first = first->next;
        
        delete(temp);

        iCount--;
        return iValue;
    }
}

template<class T>
void Queue<T> :: Display()
{
    struct node<T> * temp = NULL;
    temp = this->first;

    while(temp != NULL)
    {
        cout<<" | "<<temp->data<<" |\n";
        temp = temp->next;
    }
}

template<class T>
int Queue<T> :: Count()
{
    return iCount;
}

int main()
{
    Queue<int> sobj;
    int iRet = 0;

    sobj.Enqueue(11);
    sobj.Enqueue(21);
    sobj.Enqueue(51);
    sobj.Enqueue(101);

    sobj.Display();

    iRet = sobj.Count();
    
    cout<<"Elements of the queue are : "<<iRet<<"\n";

    iRet = sobj.Dequeue();

    cout<<"Removed element is : "<<iRet<<"\n";

    sobj.Display();

    iRet = sobj.Count();
    
    cout<<"Elements of the queue are : "<<iRet<<"\n";

    return 0;
}