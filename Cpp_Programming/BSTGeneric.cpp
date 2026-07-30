#include<iostream>
using namespace std;
#include<stdlib.h>
#include<stdbool.h>

#pragma pack(1)
template<class T>
struct node
{
    T data;
    struct node<T> *lchild;
    struct node<T> *rchild;
};

template<class T>
class BST
{
    private :
        struct node<T> * first;
        int iCount;

        void Inorder(node<T> *first);
        void Preorder(node<T> *first);
        void Postorder(node<T> *first);
        int Count(node<T> *first);
        int CountLeaf(node<T> *first); 
        int CountParent(node<T> *first);

    public :
        BST();
        
        void Inorder();
        void Preorder();
        void Postorder();
        void Insert(T iNo); 
        int Count();
        bool Search(T iNo); 
        int CountLeaf(); 
        int CountParent();

};

template<class T>
BST<T> :: BST()
{   
    this->first = NULL;
    this->iCount = 0;
}

template<class T>
//  L   D   R
void BST<T> :: Inorder(node<T> *first)
{
    if(first != NULL)
    {
        Inorder(first->lchild);
        cout<<first->data<<endl;
        Inorder(first->rchild);
    }
}

template<class T>
void BST<T> :: Inorder()
{
    Inorder(first);
}

//  D   L   R
template<class T>
void BST<T> :: Preorder(node<T> *first)
{
    if(first != NULL)
    {
        cout<<first->data<<endl;
        Preorder(first->lchild);
        Preorder(first->rchild);
    }
}

template<class T>
void BST<T> :: Preorder()
{
    Preorder(first);
}

//  L   R   D
template<class T>
void BST<T> :: Postorder(node<T> *first)
{
    if(first != NULL)
    {
        Postorder(first->lchild);
        Postorder(first->rchild);
        cout<<first->data<<endl;
    }
}

template<class T>
void BST<T> :: Postorder()
{
    Postorder(first);
}

template<class T>
void BST<T> :: Insert(T iNo)        
{
    struct node<T> * newn = NULL;
    struct node<T> * temp = NULL;

    newn = new struct node<T>;

    newn->data = iNo;
    newn->lchild = NULL;
    newn->rchild = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        temp = first;

        while(1)
        {
            if(iNo > temp->data)
            {
                if(temp->rchild == NULL)
                {
                    temp->rchild = newn;
                    break;
                }
                temp = temp->rchild;
            }
            else if(iNo < temp->data)
            {
                if(temp->lchild == NULL)
                {
                    temp->lchild = newn;
                    break;
                }
                temp = temp->lchild;
            }
            else if(iNo == temp->data)
            {
                cout<<"Unable to insert as element is duplicate"<<endl;
                delete newn;
                break;
            }
        }
    }

}

template<class T>
int BST<T> :: Count(node<T> *first)
{
    int iCount = 0;

    if(first != NULL)
    {
        iCount++;
        iCount = iCount + Count(first->lchild);
        iCount = iCount + Count(first->rchild);
    }
    return iCount;
}

template<class T>
int BST<T> :: Count()
{
    Count(first);
}

template<class T>
bool BST<T> :: Search(T iNo)
{
    bool bFlag = false;
    struct node<T> * temp = first;
    
    while(temp != NULL)
    {
        if(iNo == temp->data)
        {
            bFlag = true;
            break;
        }
        else if(iNo > temp->data)
        {
            temp = temp->rchild;
        }
        else if(iNo < temp->data)
        {
            temp = temp->lchild;
        }
    }
    return bFlag;
}

template<class T>
int BST<T> :: CountLeaf(node<T> *first)
{
    int iCount = 0;

    if(first != NULL)
    {
        if((first->rchild == NULL) && (first->lchild == NULL))
        {
            iCount++;
        }
        iCount = iCount + CountLeaf(first->lchild);
        iCount = iCount + CountLeaf(first->rchild);
    }
    return iCount;
}

template<class T>
int BST<T> :: CountLeaf()
{
    CountLeaf(first);
}

template<class T>
int BST<T> :: CountParent(node<T> *first)
{
    int iCount = 0;

    if(first != NULL)
    {
        if((first->rchild != NULL) || (first->lchild != NULL))
        {
            iCount++;
        }
        iCount = iCount + CountParent(first->lchild);
        iCount = iCount + CountParent(first->rchild);
    }
    return iCount;
}

template<class T>
int BST<T> :: CountParent()
{
    CountParent(first);
}

int main()
{
    BST<int> bobj;
    int iRet = 0;
    
    bobj.Insert(11);
    bobj.Insert(5);
    bobj.Insert(17);
    bobj.Insert(21);
    bobj.Insert(4);
    bobj.Insert(7);
    bobj.Insert(15);

    cout<<"Inorder Display : "<<endl;
    bobj.Inorder();  

    iRet = bobj.Count();

    cout<<"Number of nodes are : "<<iRet<<endl;

    if(bobj.Search(25) == true)
    {
        cout<<"25 is present in BST"<<endl;
    }
    else
    {
        cout<<"25 is not present in BST"<<endl;
    }

    iRet = bobj.CountLeaf();

    cout<<"Number of leaf nodes are : "<<iRet<<endl;

    iRet = bobj.CountParent();

    cout<<"Number of parent nodes are : "<<iRet<<endl;

    return 0;
}