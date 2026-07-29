package Java_Programming;

class node
{
    public int data;
    public node next;

    node(int no)
    {
        this.data = no;
        this.next = null;
    }
}

class SinglyCL
{
    private node first;
    private node last;
    private int iCount;

    public SinglyCL()
    {
        this.first = null;
        this.last = null;
        this.iCount = 0;
    }

    public void Display()
    {
        node temp = first;

        if(this.first == null && this.last == null)
        {
            return;
        }

        do
        {
            System.out.print(" | "+ temp.data + " | -> ");
            temp = temp.next;
        }while(this.last.next != temp);

        System.out.println();
    }

    public int Count()
    {
        return this.iCount;
    }

    public void InsertFirst(int iNo)
    {
        node newn = new node(iNo);

        if(this.first == null && this.last == null)
        {
            this.first = newn;
            this.last = newn;
        }
        else
        {
            newn.next = this.first;
            this.first = newn;
        }
        this.last.next = this.first;
        this.iCount++;

    }

    public void InsertLast(int iNo)
    {
        node newn = new node(iNo);

        if(this.first == null && this.last == null)
        {
            this.first = newn;
            this.last = newn;
        }
        else
        {
           this.last.next = newn;
           this.last = newn;
        }
        this.last.next = this.first;
        this.iCount++;

    }

    public void InsertAtPos(int iNo, int iPos)
    {
        node newn = null;
        node temp = null;
        int i = 0;

        if((iPos < 1) || (iPos > iCount + 1))
        {
            System.out.println("Invalid Position");
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
            newn = new node (iNo);

            temp = first;

            for(i = 1; i < iPos - 1; i ++)
            {
                temp = temp.next;
            }
            newn.next = temp.next;
            temp.next = newn;
            iCount++;
        }
    }

    public void DeleteFirst()
    {
        if(this.first == null && this.last == null)
        {
            return;
        }
        else if(this.first == this.last)
        {
            this.first = null;
            this.last = null;
        }
        else
        {
            this.first = this.first.next;
            this.last.next = this.first;
        }

        this.iCount --;
    }

    public void DeleteLast()
    {
        if(this.first == null && this.last == null)
        {
            return;
        }
        else if(this.first == this.last)
        {
            this.first = null;
            this.last = null;
        }
        else
        {
            node temp = first;

            while(temp.next != this.last)
            {
                temp = temp.next;
            }

            this.last = temp;
            this.last.next = this.first;
        }

        this.iCount --;
    }

    public void DeleteAtPos(int iPos)
    {
        node temp = null;
        int i = 0;

        if((iPos < 1) || (iPos > iCount))
        {
            System.out.println("Invalid Position");
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

            for(i = 1; i < iPos - 1; i ++)
            {
                temp = temp.next;
            }
            
            temp.next = temp.next.next;

            iCount--;
        }
    }

}

class SinglyCircularList 
{
    public static void main(String A [])
    {
        SinglyCL sobj = new SinglyCL();
        int iRet = 0;

        sobj.InsertFirst(51);
        sobj.InsertFirst(21);
        sobj.InsertFirst(11);

        sobj.InsertLast((101));
        sobj.InsertLast((111));
        sobj.InsertLast((121));

        sobj.Display();

        iRet = sobj.Count();

        System.out.println("Number of nodes are : "+iRet);

        sobj.DeleteFirst();

        sobj.Display();

        iRet = sobj.Count();

        System.out.println("Number of nodes are : "+iRet);

        sobj.DeleteLast();
        
        sobj.Display();

        iRet = sobj.Count();

        System.out.println("Number of nodes are : "+iRet);

        sobj.InsertAtPos(105, 4);

        sobj.Display();

        iRet = sobj.Count();

        System.out.println("Number of nodes are : "+iRet);

        sobj.DeleteAtPos(4);

        sobj.Display();

        iRet = sobj.Count();

        System.out.println("Number of nodes are : "+iRet);
    }
}