package Java_Programming;

class node
{
    public int data;
    public node lchild;
    public node rchild;

    node(int no)
    {
        data = no;
        lchild = null;
        rchild = null;
    }
}

class BSTX
{
    private node first;
    
    public BSTX()
    {
        first = null;
    }

    public void Inorder(node first)
    {
        if(first != null)
        {
            Inorder(first.lchild);
            System.out.println(first.data);
            Inorder(first.rchild);
        }
    }

    public void Inorder()
    {
        Inorder(first);
    }

    public void Preorder(node first)
    {
        if(first != null)
        {
            System.out.println(first.data);
            Preorder(first.lchild);
            Preorder(first.rchild);
        }
    }

    public void Preorder()
    {
        Preorder(first);
    }

    public void Postorder(node first)
    {
        if(first != null)
        {
            Postorder(first.lchild);
            Postorder(first.rchild);
            System.out.println(first.data);
        }
    }

    public void Postorder()
    {
        Postorder(first);
    }

    public void Insert(int iNo)
    {
        node newn = new node(iNo);
        node temp = null;

        newn.data = iNo;
        newn.lchild = null;
        newn.rchild = null;

        if(first == null)
        {
            first = newn;
        }
        else
        {
            temp = first;

            while(true)
            {
                if(iNo > temp.data)
                {
                    if(temp.rchild == null)
                    {
                        temp.rchild = newn;
                        break;
                    }
                    temp = temp.rchild;
                }
                else if(iNo < temp.data)
                {
                    if(temp.lchild == null)
                    {
                        temp.lchild = newn;
                        break;
                    }
                    temp = temp.lchild;
                }
                else if(iNo == temp.data)
                {
                    System.out.println("Unable to insert as element is duplicate");
                    break;
                }
            }
        }
    }

    public int Count(node first)
    {
        int iCount = 0;

        if(first != null)
        {
            iCount++;
            iCount = iCount + Count(first.lchild);
            iCount = iCount + Count(first.rchild);
        }
        return iCount;
    }

    public int Count()
    {
        return Count(first);
    }

    public boolean Search(int iNo)
    {
        boolean bFlag = false;
        node temp = first;

        while(temp != null)
        {
            if(iNo == temp.data)
            {
                bFlag = true;
                break;
            }
            else if(iNo > temp.data)
            {
                temp = temp.rchild;
            }
            else if(iNo < temp.data)
            {
                temp = temp.lchild;
            }
        }
        return bFlag;
    }

    public int CountLeaf(node first)
    {
        int iCount = 0;

        if(first != null)
        {
            if((first.rchild == null) && (first.lchild == null))
            {
                iCount++;
            }
            iCount = iCount + CountLeaf(first.lchild);
            iCount = iCount + CountLeaf(first.rchild);
        }
        return iCount;
    }

    public int CountLeaf()
    {
        return CountLeaf(first);
    }

    public int CountParent(node first)
    {
        int iCount = 0;

        if(first != null)
        {
            if((first.rchild == null) || (first.lchild == null))
            {
                iCount++;
            }
            iCount = iCount + CountParent(first.lchild);
            iCount = iCount + CountParent(first.rchild);
        }
        return iCount;
    }

    public int CountParent()
    {
        return CountParent(first);
    }
}

class BinaryTreeDS 
{
    public static void main(String args[])
    {
        BSTX bobj = new BSTX();
        int iRet = 0;

        bobj.Insert(11);
        bobj.Insert(5);
        bobj.Insert(17);
        bobj.Insert(21);
        bobj.Insert(4);
        bobj.Insert(7);
        bobj.Insert(15);

        System.out.println("Inorder Display : ");
        bobj.Inorder();

        iRet = bobj.Count();

        System.out.println("Number of nodes are : " +iRet);

        if(bobj.Search(25) == true)
        {
            System.out.println("25 is present in BST");
        }
        else
        {
            System.out.println("25 is not present in BST");
        }

        iRet = bobj.CountLeaf();

        System.out.println("Number of leaf nodes are : "+iRet);

        iRet = bobj.CountParent();

        System.out.println("Number of parents nodes are : "+iRet);
    }    
}