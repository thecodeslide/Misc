/**
 * Remote Interface for the implementation.
 */
public interface theInterface extends java.rmi.Remote
{
        /**
		 * Remotely invocable methods.
		 * @return the value of the remote object, such as sum of 2 variables.
		 * @exception RemoteException if the remote invocation fails.
		 */
		public java.util.Date getDate() throws java.rmi.RemoteException;
		double add(double d1, double d2) throws java.rmi.RemoteException; 
}
