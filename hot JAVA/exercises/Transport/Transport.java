/*
  1 +  2 +  3 +  4
 
 */
public abstract class Transport implements TransportInterface{
    private int passengers, capacity;
    public Transport(int c, int p)
    {
        passengers=0;
        capacity=c;
    }
    
    protected int getNumberPassengers()
    {
     return this.passengers;   
    }
    
    protected int getTransCapacity()
    {
        return capacity;
    }
    
    public void numberPassengers()
    {
        
    }
    
    public void getOn(int p)
    {
        //int num=passengers;
        int num=getNumberPassengers()+p;
		
        if(num<=capacity)
       {
            passengers=num;
            System.out.println(+num);
        }
        else 
        {
            System.out.println("ERROR! Capacity exceeded");
            System.out.println("Setting passengers to limit!");
           // num=capacity;
            passengers=capacity;
            System.out.println("Passenger count adjusted to: "+capacity);
        }
     //   return passengers;
    }
    
    public void getOff(int p)
    {
       // int num=getNumberPassengers();
        int num=this.passengers-p;
        if(num>=capacity)
        {
            passengers=num;
        }
        else System.out.println("ERROR! Passengers cannot be negative value");
    }
    
    public boolean equals(Object Obj)
    {
        if(Obj instanceof Transport)
        {
            Transport T=(Transport)Obj;
            if(T.passengers==passengers&&T.capacity==capacity)
                return true;
        }
        return false;
    } 
    
    public static Object getDestination(Transport Obj) //to print next destination
    {
        if(Obj instanceof Bus)
        {
            Bus bus=(Bus)Obj;
            return bus.getNextStopNumber();
        }
        else if(Obj instanceof Train) 
        {
            Train t=(Train)Obj;
            return t.getNameNextStation();
        }
        else if(Obj instanceof Boat) 
        {
            Boat b=(Boat)Obj;
            return b.getNamePort();
        }
        else return 1;  
    }
}
