package Java_Programming;

import java.util.Scanner;

class Searching
{
    private int Arr[];
    private int iSize;

    public Searching(int iNo)
    {
        iSize = iNo;
        Arr = new int[iSize];
    }
    
    public void Accept()
    {
        int i = 0;

        Scanner sobj = new Scanner(System.in);

        System.out.println("Enter the elements :");

        for(i = 0; i < iSize; i++)
        {
            Arr[i] = sobj.nextInt();
        }
    }

    public void Display()
    {
        int i = 0;

        System.out.println("Elements of the array are : ");

        for(i = 0; i < iSize; i++)
        {
            System.out.println(Arr[i]);
        }
    }

    boolean LinearSearch(int iNo)
    {
        boolean bFlag = false;
        int i = 0;

        for(i = 0; i < iSize; i++)
        {
            if(iNo == Arr[i])
            {
                bFlag = true;

                break;
            }
        }

        return bFlag;
    }

    boolean BiDirectionalSearch(int iNo)
    {
        boolean bFlag = false;
        int iStart = 0;
        int iEnd = 0; 

        iStart = 0;
        iEnd = iSize - 1;
        
        while(iStart <= iEnd)
        {
            if((Arr[iStart] == iNo) || (Arr[iEnd] == iNo))
            {
                bFlag = true;

                break;
            }

            iStart++;
            iEnd--;
        }

        return bFlag;
    }

}

class Searching_Node 
{
    public static void main(String A[])
    {
        int iValue = 0;

        Scanner sobj = new Scanner(System.in);

        System.out.println("Enter the number of elements : ");
        int iLength = sobj.nextInt();

        Searching ssobj = new Searching(iLength);

        ssobj.Accept();
        ssobj.Display();

        System.out.println("Enter the element to search");
        iValue = sobj.nextInt();

        if(ssobj.LinearSearch(iValue) == true)
        {
            System.out.println("Element is present");
        }
        else 
        {
            System.out.println("There is no such elements ");
        }

        if(ssobj.BiDirectionalSearch(iValue) == true)
        {
            System.out.println("Element is present");
        }
         else 
        {
            System.out.println("Element is not present");
        }
        
    }
}
