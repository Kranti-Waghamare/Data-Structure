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

class StackX
{
    private node first;
    private int iCount;

    public StackX()
    {
        first = null;
        iCount = 0;
    }

    public void Push(int iNo)
    {
        node newn = new node(iNo);

        newn.data = iNo;
        newn.next = null;

        newn.next = first;
        first = newn;

        iCount++;
    }

    public int Pop()
    {
        int iValue = 0;

        if(first == null)
        {
            System.out.println("Stack is empty");
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

    public int Peep()
    {
        int iValue = 0;

        if(first == null)
        {
            System.out.println("Stack is empty");
            return -1;
        }
        else
        {
            iValue = first.data;

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

class StackDS 
{
    public static void main(String args[])
    {
        StackX sobj = new StackX();
        int iRet = 0;

        sobj.Push(11);
        sobj.Push(21);
        sobj.Push(51);
        sobj.Push(101);

        sobj.Display();

        iRet = sobj.Count();

        System.out.println("Elemets of the stack are : " + iRet);

        iRet = sobj.Pop();

        System.out.println("Popped element is : " +iRet);

        sobj.Display();

        iRet = sobj.Count();

        System.out.println("Elemets of the stack are : " + iRet);

        iRet = sobj.Peep();

        System.out.println("Peeped element is :" + iRet);

        sobj.Display();

        iRet = sobj.Count();

        System.out.println("Elemets of the stack are : " + iRet);

    }
}
