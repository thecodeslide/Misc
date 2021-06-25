import java.rmi.*;
import java.rmi.server.UnicastRemoteObject;
/**
 * Remote Class for the implementation.
 */

public class theImp extends UnicastRemoteObject implements theInterface
{
  /**
   * Construct a remote object
   * @exception RemoteException if the object handle cannot be constructed.
   */
		public theImp(String name) throws RemoteException
                {
                super();
                try
                        {
                        Naming.rebind(name, this);
						System.out.println ("Hello Server is ready.");
                        }
                catch(Exception e)
                        {
                        System.out.println("Exception occurred: " + e);
                        }
                }
  /**
   * Implementation of the remotely invocable method.
   * @retval date the date of the remote server.
   * @retval values of the remote object, such as addition of 2 variables d1 and d2".
   * @exception RemoteException if the remote invocation fails.
   */
        public java.util.Date getDate()
                {
                return new java.util.Date();
                }
		public double add(double d1, double d2) throws RemoteException 
				{
				return d1 + d2;
				} 
}
