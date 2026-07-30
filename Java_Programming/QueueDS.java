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

class QueueX
{
    private node first;
    private int iCount;

    public QueueX()
    {
        first = null;
        iCount = 0;
    }

    public void Enqueue(int iNo)
    {
        node newn = new node(iNo);
        node temp = null;

        newn.data = iNo;
        newn.next = null;

        if(first == null)
        {
            first = newn;
        }
        else
        {
            temp = first;

            while(temp.next != null)
            {
                temp = temp.next;
            }

            temp.next = newn;
        }
        
        iCount++;
    }

    public int Dequeue()
    {
        int iValue = 0;

        if(first == null)
        {
            System.out.println("Queue is empty");
            return -1;
        }
        else
        {
            iValue = first.data;
            first = first.next;

            iCount--;
            return iValue;
        }
    }

    public void Display()
    {
        node temp = null;
        temp = first;

        while(temp != null)
        {
            System.out.println(" | "+temp.data +" | ");
            temp = temp.next;
        }
    }

    public int Count()
    {
        return iCount;
    }
}

class QueueDS 
{
    public static void main(String args[])
    {
        QueueX sobj = new QueueX();
        int iRet = 0;

        sobj.Enqueue(11);
        sobj.Enqueue(21);
        sobj.Enqueue(51);
        sobj.Enqueue(101);

        sobj.Display();

        iRet = sobj.Count();

        System.out.println("Elemets of the stack are : " + iRet);

        iRet = sobj.Dequeue();

        System.out.println("Removed element is : " +iRet);

        sobj.Display();

        iRet = sobj.Count();

        System.out.println("Elemets of the stack are : " + iRet);
    }
}