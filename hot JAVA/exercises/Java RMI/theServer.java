import java.rmi.*;
import java.rmi.server.UnicastRemoteObject;

public class theServer
{
  /**
   * Server program for the implementation.
   */
		public static void main(String args[])
                {
                try
                        {
                        theImp implementation = new theImp("theImpInstance");
						Naming.rebind("theImpInstance", implementation);
                        }
                catch (Exception e)
                        {
                        System.out.println("Exception occurred: " + e);
                        }
                }
}

