import java.rmi.*;
import java.rmi.registry.*;
import java.rmi.server.*;
import java.util.Date;
import java.util.Scanner;

public class myRMIClient
{
        public static void main(String args[])
                {
				 if (args.length < 1)
                        {
                        System.out.println("usage: java myRMIClient <IP address of host running RMI server>");
                        System.exit(0);
                        } 
                String serverName = args[0];
                try
                        {
                                        //bind server object to object in client
                        theInterface myServerObj = (theInterface) Naming.lookup("rmi://"+serverName+"/theImpInstance");

                                        //invoke method on server object
                        Date d = myServerObj.getDate();
                        System.out.println("Date on server is :" + d);
						System.out.println("Price of Fish is $: " + args[1]);
						  double priceFish = Double.valueOf(args[1]).doubleValue();
						  System.out.println("Price of apple is $: " + args[2]);

						  double priceApple = Double.valueOf(args[2]).doubleValue();
						  System.out.println("Please make a total payment of $: " + myServerObj.add(priceFish, priceApple));
						  Scanner reader=new Scanner(System.in);
		
						System.out.print("Please enter amount to transfer: ");
						double a = reader.nextDouble();
							if(a == myServerObj.add(priceFish, priceApple))
								System.out.println("You have paid : $" + a + " \nThank you and have a nice day!");
							else
								System.out.println("Error. Please contact a staff member for assistance.");
                        }
                catch(Exception e)
                        {
                        System.out.println("Exception occured: " + e);
                        System.exit(0);
                        }
                System.out.println("RMI connection successful");
                }
        

}
