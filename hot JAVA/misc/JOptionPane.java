import java.util.Scanner;
import javax.swing.JOptionPane;
class QS4 {

public static void main(String args[]) {

int num[] = new int[10];//creating the array
int i=0;//variable values
int search;//initialising variable
int low = 0;
int high = 9;
int mid;
int menu;
int count=1;
        String SumString="";//joptionpane creating
        String QString= JOptionPane.showInputDialog ("Select Search type \n"

                + "1= Binary Search \n"
                + "2= Linear Search \n");
        menu= Integer.parseInt(QString);

  if (menu==1)//choice of menu
        {

Scanner reader = new Scanner (System.in);//initialing scanner
//Accepting 10 elements
for(i=0;i<10;i++)//loop for binary sreach
{
    System.out.println("Enter elements:");//prompt for input
    num[i] = reader.nextInt();//saving input
}
//Search element
System.out.println ("Enter desired search value");//prompt for input to be search
search = reader.nextInt();//saving value

while(low<=high)//loop for searching
{
    mid = (low+high)/2;//conditions

       if (search ==num[mid])//checking of conditions
         {
            System.out.println ("Element is located in:"+ (mid+1));//display message
            break;//ending loop if condition is true
         }
 else
     if(search <num[mid])//conditions to check if above are false
         high =mid-1;
  else
      low = mid+1;

            }
    }
else if (menu == 2)//menu option 2
        {


      Scanner reader = new Scanner (System.in);
//Accepting 10 elements
for(i=0;i<10;i++)
{
    System.out.println("Enter elements:");//prompt for entering elements
    num[i] = reader.nextInt();//saving value for array
}
//Search element
System.out.println ("Enter desired search value");//prompt for search value
search = reader.nextInt();//saving the search value

for(i=0;i<10;i++)//loop for searching
{
    if(search == num[i])//conditions
    {
    System.out.printf("element is located at slot "+count+" of the array");//if conditions is true
    break;//ending of loop if condition is met
    }
    else//if condition is not met

    count=count+1;//increasing the count so as to know placing of value
            }

  }

   else

     {

    JOptionPane.showMessageDialog(null,"        \"Invalid menu option");


        }
    }
} 
