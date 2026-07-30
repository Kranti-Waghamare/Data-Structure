#include<iostream>
using namespace std;
#include<stdlib.h>
#include<stdbool.h>

#pragma pack(1)
struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
};

class BST
{
    private :
        struct node * first;
        int iCount;

        void Inorder(node *first);
        void Preorder(node *first);
        void Postorder(node *first);
        int Count(node *first);
        int CountLeaf(node *first); 
        int CountParent(node *first);

    public :
        BST();
        
        void Inorder();
        void Preorder();
        void Postorder();
        void Insert(int iNo); 
        int Count();
        bool Search(int iNo); 
        int CountLeaf(); 
        int CountParent();

};

BST :: BST()
{   
    this->first = NULL;
    this->iCount = 0;
}

//  L   D   R
void BST :: Inorder(node *first)
{
    if(first != NULL)
    {
        Inorder(first->lchild);
        cout<<first->data<<endl;
        Inorder(first->rchild);
    }
}

void BST :: Inorder()
{
    Inorder(first);
}

//  D   L   R
void BST :: Preorder(node *first)
{
    if(first != NULL)
    {
        cout<<first->data<<endl;
        Preorder(first->lchild);
        Preorder(first->rchild);
    }
}

void BST :: Preorder()
{
    Preorder(first);
}

//  L   R   D
void BST :: Postorder(node *first)
{
    if(first != NULL)
    {
        Postorder(first->lchild);
        Postorder(first->rchild);
        cout<<first->data<<endl;
    }
}

void BST :: Postorder()
{
    Postorder(first);
}

void BST :: Insert(int iNo)        
{
    struct node * newn = NULL;
    struct node * temp = NULL;

    newn = new struct node;

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

int BST :: Count(node *first)
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

int BST :: Count()
{
    return Count(first);
}

bool BST :: Search(int iNo)
{
    bool bFlag = false;
    struct node * temp = first;
    
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

int BST :: CountLeaf(node *first)
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

int BST :: CountLeaf()
{
    return CountLeaf(first);
}

int BST :: CountParent(node *first)
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

int BST :: CountParent()
{
    return CountParent(first);
}

int main()
{
    BST bobj;
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