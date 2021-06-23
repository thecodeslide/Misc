/*
 1 +  2 +  3 +  4
 */
public class Train extends Transport implements TransportInterface{
    private String namestation, engine; 
    private int carriages;
    
    public Train(String nameofstation, String enginetype, int numcarriages, int c, int p)
    {
        super(c,p); // call to base class
       // super.getTransCapacity();
        this.namestation=nameofstation;
        this.engine=enginetype;
        this.carriages=numcarriages;
    }
    
    public void setNameStation(String tns)
    {
        namestation=tns;
    }
    
    public String getNameNextStation()
    {
        return namestation;
    }
    
    public int getNumberCarriages()
    {
        return carriages;
    }
    
    public String getEngineType()
    {
        return engine;
    }
    
    public int getTransCapacityT()
    {
        //return this.capacity;
        return getTransCapacity();
    }
    
    public int getPassengerT()
    {
      //  return this.passengers;
        return getNumberPassengers();
    }
    
    public String toString()
    {
        return "Train toString: station- "+namestation+", engine "+engine+", carriages- "+
                carriages+", capacity- "+getTransCapacityT()+", passengers- "+getPassengerT();
    }
    
    public boolean equals(Object Obj)
    {
        if(!super.equals(Obj))
            return false;
        if(Obj instanceof Train)
        {
            Train t=(Train)Obj;
            if(t.namestation.equalsIgnoreCase(namestation)
                    &&t.engine.equalsIgnoreCase(engine)&&t.carriages==carriages)
                return true;
        }
        return false;
    } 
}
