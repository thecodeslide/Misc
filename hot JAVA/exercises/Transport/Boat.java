/*
1 +  2 +  3 +  4
 */
public class Boat extends Transport implements BoatInterface{
    private String nameport;
    
    public Boat(String portname, int c, int p)
    {
        super(c,p); // call to base class
        //super.getTransCapacity();
        nameport=portname;
    }
    
    public void setNameNextPort(String nport)
    {
        nameport=nport;
    }
    
    public String getNamePort()
    {
        return nameport;
    }
    
    public int getTransCapacityB()
    {
       // return capacity;
        return getTransCapacity();
    }
    
    public int getPassengerB()
    {
      //  return this.passengers;
        return getNumberPassengers();
    }
    
    public String toString()
    {
        return "Boat toString: next port- "+nameport+", capactiy- "+
                getTransCapacityB()+", passengers- "+getPassengerB();
    }
    
    public boolean equals(Object Obj)
    {
        if(Obj instanceof Boat)
        {
            Boat b=(Boat)Obj;
            if(b.nameport.equalsIgnoreCase(nameport))
                return true;
        }
        return false;
    }
}
