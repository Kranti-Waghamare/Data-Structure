//Singly Linear linked list in Java.

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

class SinglyLL
{
    private node first;
    private int iCount;

    public SinglyLL()
    {
        this.first = null;
        this.iCount = 0;
    }

    public void Display()
    {
        node temp = first;

        while(temp != null)
        {
            System.out.print(" | "+ temp.data + " | -> ");
            temp = temp.next;
        }

        System.out.println("null ");
    }

    public int Count()
    {
        return this.iCount;
    }

    public void InsertFirst(int iNo)
    {
        node newn = new node(iNo);

        if(this.first == null)
        {
            this.first = newn;
        }
        else
        {
            newn.next = this.first;
            this.first = newn;
        }
        this.iCount++;

    }

    public void InsertLast(int iNo)
    {
        node newn = new node(iNo);

        if(this.first == null)
        {
            this.first = newn;
        }
        else
        {
            node temp = this.first;

            while(temp.next != null)
            {
                temp = temp.next;
            }

            newn.next = temp.next;
            temp.next = newn;

        }
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
        if(this.first == null)
        {
            return;
        }
        else if(this.first.next == null)
        {
            this.first = null;
        }
        else
        {
            this.first = this.first.next;
        }

        this.iCount --;
    }

    public void DeleteLast()
    {
        if(this.first == null)
        {
            return;
        }
        else if(this.first.next == null)
        {
            this.first = null;
        }
        else
        {
            node temp = first;

            while(temp.next.next != null)
            {
                temp = temp.next;
            }

            temp.next = null;
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

class SinglyLinearList
{
    public static void main(String A [])
    {
        SinglyLL sobj = new SinglyLL();
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