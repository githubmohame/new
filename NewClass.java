import java.util.Arrays;
import java.util.Date;
import java.util.Scanner;
import java.util.stream.Stream;
/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author mohamed
 */
public class NewClass {
    @SuppressWarnings("empty-statement")
    static public void main(String[] arg)
            {
                //Assignment 1 section1
                /*
                 Scanner sc = new Scanner(System.in);
                 int i = sc.nextInt();
                 String s1=String.valueOf(i);
                 for(int k=0;k<s1.length()-1;k++)
                 {
                     if(s1.charAt(k)!=s1.charAt(s1.length()-k-1))
                     {
                        System.out.print("the number is not palindrome");
                        return ;
                     }
                 }
                System.out.print("the number is palindrome");
                */
                
                
                //Assignment 2 section1
                /*                
                Scanner sc=new Scanner(System.in);
                if(sc.nextInt()%2!=0)
                {
                    System.out.print("the number is odd");
                    return;
                }
                System.out.print("the number is even");
                */
                
                
                //Assignment 3 section1
                /*
                Scanner sc=new Scanner(System.in);
                double i1=sc.nextDouble(),i2=sc.nextDouble(),i3=sc.nextDouble();
                if(i1+i2>i3&&i3+i2>i1&&i1+i3>i2)
                {
                    System.out.print(i1+i2+i3);
                    return;
                }
                System.out.print("the numbers are not valid");
                */
                
                
                
                
                //Assignment 1 section 2
                /*
                Scanner sc=new Scanner(System.in);
                double i=sc.nextDouble();
                System.out.print(i*0.454);
                */
                
                
                
                
                
                
                //Assignment 2 section2
                /*
                Scanner sc=new Scanner(System.in);
               double i=sc.nextDouble();
               int  years=(int)(i/(60*24*365));
               int days=-(int)((years-(i/(60*24*365)))*365);
               System.out.print("the number days is"+String.valueOf(days)+"\n");
               System.out.print("the number of years is"+String.valueOf(years)+"\n");
                */
                
                
                
                
                //Assignment 1 section 4
                /*
                 Scanner sc = new Scanner(System.in);
                 String s1=sc.nextLine();
                 for(int k=0;k<s1.length()-1;k++)
                 {
                     if(s1.charAt(k)!=s1.charAt(s1.length()-k-1))
                     {
                        System.out.print("the number is not palindrome");
                        return ;
                     }
                 }
                 System.out.print("the number is palindrome");
               */
                
                
                
                
                
                //Assignment 2 section 4
                /*
                double input=1;
                double sum=0;
               double u;
                int avg=0;
               do
               {
                   Scanner sc=new Scanner(System.in);
                   while(sc.hasNextDouble())
                   {
                       u=Double.valueOf(sc.next());
                       if(u==0)
                       {
                           input=0;
                           break;
                       }
                       sum+=u;
                       avg++;
                   }
               }while(input!=0d);
                System.out.print("the sum= "+String.valueOf(sum)+"\n");
                System.out.print("the avg= "+String.valueOf(sum/avg)+"\n");
                */
                
                
                
                //Assignment 3 section 4
                /*
                for(int i=4;i>=0;i--)
                {
                    for(int i2=1;i2<=5-i;i2++)
                    {
                         System.out.print(i2);
                    }
                    System.out.print("\t");
                    for(int i2=1;i2<=5+i-4;i2++)
                    {
                         System.out.print(i2);
                    }
                    System.out.println();
                }
                */
                
                
                
                //Assignment 1 section 5
                /*
                Scanner sc = new Scanner(System.in);
                int i = sc.nextInt();
                Boolean f=NewClass.ispalindrome(i);
                if(f)
                {
                    System.out.print("the number is  palindrome");
                }
                else
                    System.out.print("the number is not palindrome");
                */
                
                
                
                
                
                
                 //Assignment 2 section 5
                /*
                Scanner sc1=new Scanner(System.in);
                 double x1=sc1.nextDouble();
                 double x2=sc1.nextDouble();
                 double x3=sc1.nextDouble();
                 NewClass.displaySortedNumber(x1, x2, x3);
                 */
                
                
                
                
                
                //Assignment 3 section 5
                /*
                 System.out.print("from fah to ceil enter 1\n from ceil to fah enter2  and entre the value\n");
                 Scanner sc1=new Scanner(System.in);
                 int y=sc1.nextInt();
                 double x1=sc1.nextDouble();
                 if(y==1)
                 {
                     System.out.print("the ceil value= "+Calc.fahToCel(x1));
                 }
                 else
                 {
                     System.out.print("the fah value= "+Calc.celToFah(x1));
                 }
                */
                
                
                //Assignment 1 section 6
                /*
                System.out.print("enter the number of elements");
                Scanner sc=new Scanner(System.in);
                int size=sc.nextInt();
                String[] arr  ;
                arr=new String[size];
                int i=0;
                while(true)
                {
                    while(sc.hasNext())
                    {
                        arr[i]=String.valueOf(sc.nextDouble());
                        i++;
                        if(i>=size)
                        {
                            break;
                        }
                    }
                    if(i>=size)
                    {
                        break;
                    }
                    sc.delimiter();
                }
                System.out.print("for int enter 1 for double press 2 \n");
                sc.delimiter();
                sc.delimiter();
                int flage=sc.nextInt();
                 if(flage==1)
                 {
                 	double[] arr2 = Arrays.stream(arr).mapToDouble(Double::parseDouble).toArray();
                	System.out.print(average(arr2));
                	
                 }
                 else{
                 	int[] arr2;
                    arr2 = Stream.of(arr).mapToInt(Integer::parseInt).toArray();
                 	System.out.print(average(arr2));	
                     }
                     */
                     
                     
                     
                 //Assignment 2 section 6
                 /*
                System.out.print("enter the number");
                Scanner sc=new Scanner(System.in);
                int arr[];
                arr=new int[100];
                int i=0;
                int flage=0;
                while(true)
                {
                    while(sc.hasNext())
                    {
 			flage=sc.nextInt();
                        if(flage<0){
                        break;
                        }
                        arr[i]=flage;
                        i++;
                        if(i==100)
                        {
                            break;
                        }
                    }
                    if(i==100)
                    {
                        break;
                    }
                    if(flage<0){
                    break;
                    }
                    sc.delimiter();
                }
                System.out.print(String.valueOf(i)+"\n");
                System.out.print(average(arr,i));
                */
                
                
                //Assignment 3 section 6
                /*
                Scanner sc1=new Scanner(System.in);
                int width=sc1.nextInt();
                int height=sc1.nextInt();
                double a[][]=new double[width][height];
                double b[][]=new double[width][height];
                for(int i1=0;i1<a.length;i1++)
          	{
          		for(int i2=0;i2<a[0].length;i2++)
          		{
                                sc1.delimiter();
          			a[i1][i2]=sc1.nextDouble();
          		}
          	}
                for(int i1=0;i1<b.length;i1++)
          	{
          		for(int i2=0;i2<b[0].length;i2++)
          		{
                                sc1.delimiter();
          			b[i1][i2]=sc1.nextDouble();
          		}
          	}
                addMatrix(a,b);
                */
            //Assignment 1 section 6
            /*
            StopWatch w1=new StopWatch();
             w1.start();
             w1.stop();
             System.out.print(w1.getElapsedTime());
             */
             //Assignment 2 section 7
             Stock s1=new Stock("jjkk");
             s1.currentPrice=20.5778d;
             s1.previousClosingPrice=10.503;
             System.out.print(s1.getChangePercent()+"%");
             
        }
    	    
    	    
    	    
            //Assignment 1 section 5 method
           /*
           public static  Boolean ispalindrome(int input)
           {
                 int i = input;
                 String s1=String.valueOf(i);
                 for(int k=0;k<s1.length()-1;k++)
                 {
                     if(s1.charAt(k)!=s1.charAt(s1.length()-k-1))
                     {
                        return false;
                     }
                 }
                 return true;
           }
           */
    
            //Assignment 2 section 5
            /*
            public static void displaySortedNumber(double num1,double num2,double num3)
            {
                if(num1>=num2&&num2>=num3)
                {
                    System.out.print(num1+"  "+num2+"  "+num3+"\n");
                }
              else  if(num1>=num3&&num3>=num2)
                {
                     System.out.print(num1+"  "+num3+"  "+num2+"\n");
                }
                else if(num2>=num1&&num1>=num3)
                {
                     System.out.print(num2+"  "+num1+"  "+num3+"\n");
                }
               else if(num2>=num3&&num3>=num1)
                {
                     System.out.print(num2+"  "+num3+"  "+num1+"\n");
                }
                else if(num3>=num2&&num2>=num1)
                {
                     System.out.print(num3+"  "+num2+"  "+num1+"\n");
                } 
                else if(num3>=num1&&num1>=num2)
                {
                     System.out.print(num3+"  "+num1+"  "+num2+"\n");
                }
            }
           */
           
           
           //Assignment 1 section 6
           /*
           static public int average(int arr[])
           {
               int sum=0;
               for(int i=0;i<arr.length;i++)
               {
                   sum+=(int)(arr[i]);
               }
               return (int)(sum/arr.length);
           }
           static public double average(double arr[])
           {
               double sum=0;
               for(int i=0;i<arr.length;i++)
               {
                   sum+=arr[i];
               }
               return (sum/arr.length);
           }
           */
           
           
           
          //Assignment 2 section 6
          /*
           static public int average(int arr[],int size)
           {
               int sum=0;
               for(int i=0;i<size;i++)
               {
                   sum+=arr[i];
               }
               return sum/size;
           }
           */
           //Assignment 3 section 6
    /*
           public static  double[][]addMatrix(double[][] a, double[][] b)
           {
          	double arr[][];
          	arr=new double[a.length][a[0].length];
          	for(int i1=0;i1<a.length;i1++)
          	{
          		for(int i2=0;i2<a[0].length;i2++)
          		{
          			arr[i1][i2]=a[i1][i2]+b[i1][i2];
          		}
          	}
          	return arr;
           }  
    */  
}
//Assignment 3 section 5
/*
 class Calc 
{
     public static double fahToCel(double x)
     {
         return (5/9.0)*(x-32);
     }
     public static double celToFah(double x)
     {
         return (9.0/5)*x-32;
     }
}
*/
//Assignment 1 section 7
/*
class StopWatch
{
    Date startTime;
    Date endTime;
    StopWatch()
    {
        startTime = new Date();
    }
    void start()
    {
        startTime = new Date();
    }
    void stop()
    {
        endTime=new Date();
    }
    long getElapsedTime() 
    {
        return  endTime.getTime()-startTime.getTime();
    }
}
*/
//Assignment 2 section 7
/*
class Stock
{
       String name;
       public double previousClosingPrice;
       public double currentPrice;
       Stock(String name )
       {
           this.name=name;
       }
       double getChangePercent() 
       {
           return (currentPrice/previousClosingPrice)*100;
       }
}
*/
