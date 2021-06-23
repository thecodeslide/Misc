/*
1 +  2 +  3 +  4
 */
public class Bus extends Transport implements BusInterface{
    private int busroutenumber, busnextstopnumber;
    
    public Bus(int busroute, int busnextstop, int c, int p)
    {
        super(c,p); // call to base class
     //   super.getTransCapacity();
        this.busroutenumber=busroute;
        this.busnextstopnumber=busnextstop;
    }
    
    public void setStopNumber(int bsn)
    {
        busnextstopnumber=bsn;
    }
    
    public int getRouteNumber()
    {
        return busroutenumber;
    }
    
    public int getNextStopNumber()
    {
       return busnextstopnumber;
    }
    
    public int getTransCapacityB()
    {
        //return this.capacity;
        return getTransCapacity();
    }
    
    public int getPassenger()
    {
        return getNumberPassengers();
    }
    
    public String toString()
    {
        return "Bus toString: route- "+busroutenumber+", stop- "+busnextstopnumber+
                ", capacity- "+getTransCapacityB()+", passengers- "+getPassenger();
    }
    
    public boolean equals(Object Obj)
    {
        if(!super.equals(Obj))
            return false;
        if(Obj instanceof Bus)
        {
            Bus b=(Bus)Obj;
            if(b.busroutenumber==busroutenumber&&b.busnextstopnumber==busnextstopnumber)
                return true;
        }
        return false;
    } 
}
