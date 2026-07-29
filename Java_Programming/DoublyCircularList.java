//Doubly circular linked list in Java.

package Java_Programming;

class node
{
    public int data;
    public node next;
    public node prev;

    node(int no)
    {
        this.data = no;
        this.next = null;
        this.prev = null;
    }
}

class DoublyCL
{
    private node first;
    private node last;
    private int iCount;

    public DoublyCL
()
    {
        this.first = null;
        this.last = null;
        this.iCount = 0;
    }

    public void Display()
    {
        if(this.first == null && this.last == null)
        {
           return;
        }

        System.out.println("<=>");

        do
        {
            System.out.print(" | "+ this.first.data + " | <=> ");
            first = first.next;
        }while(this.first != this.last.next);

        System.out.println();
    }

    public int Count()
    {
        node temp = null;
        temp = first;
        int iCount = 0;

        if(this.first == null && this.last == null)
        {
           return iCount;
        }

        do
        {
            iCount++;
            temp = temp.next;
        }while(temp != this.last.next);

        return this.iCount;
    }

    public void InsertFirst(int iNo)
    {
        node newn = new node(iNo);

        if(this.first == null && this.last == null)
        {
            this.first = newn;
            this.last = newn;
            newn.next = newn;
            newn.prev = newn;
        }
        else
        {
            newn.next = this.first;
            this.first.prev = newn;
            newn.prev = this.last;
            this.last.next = newn;
            this.first = newn;
        }

        this.last.next = this.first;
        this.first.prev = this.last;
        this.iCount++;
    }

    public void InsertLast(int iNo)
    {
        node newn = new node(iNo);

        if(this.first == null && this.last == null)
        {
            this.first = newn;
            this.last = newn;
            newn.next = newn;
            newn.prev = newn;
        }
        else
        {
            newn.prev = this.last;
            this.last.next = newn;
            newn.next = this.first;
            this.first.prev = newn;
            this.last = newn;
        }

        this.last.next = this.first;
        this.first.prev = this.last;
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
            newn.next.prev = newn;
            temp.next = newn;
            temp.prev = temp;
            iCount++;
        }
    }

    public void DeleteFirst()
    {
        if(this.first == null && last == null)
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
            this.first.prev = this.last;
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
            this.last = this.last.prev;
            this.last.next = this.first;
            this.first.prev = this.last;
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
            temp.next.prev = temp;

            iCount--;
        }
    }

}

class DoublyCircularList
{
    public static void main(String A [])
    {
        DoublyCL dobj = new DoublyCL();
        int iRet = 0;

        dobj.InsertFirst(51);
        dobj.InsertFirst(21);
        dobj.InsertFirst(11);

        dobj.InsertLast((101));
        dobj.InsertLast((111));
        dobj.InsertLast((121));

        dobj.Display();

        iRet = dobj.Count();

        System.out.println("Number of nodes are : "+iRet);

        dobj.DeleteFirst();

        dobj.Display();

        iRet = dobj.Count();

        System.out.println("Number of nodes are : "+iRet);

        dobj.DeleteLast();
        
        dobj.Display();

        iRet = dobj.Count();

        System.out.println("Number of nodes are : "+iRet);

        dobj.InsertAtPos(105, 4);

        dobj.Display();

        iRet = dobj.Count();

        System.out.println("Number of nodes are : "+iRet);

        dobj.DeleteAtPos(4);

        dobj.Display();

        iRet = dobj.Count();

        System.out.println("Number of nodes are : "+iRet);
    }
}