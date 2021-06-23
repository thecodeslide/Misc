/*
 1 +  2 +  3 +  4
 */
import java.util.Scanner;
public class TransportTest {
    public static void main(String[] args)
    {
        Bus busDriver=new Bus(26,58,50,0);
        Train trainDriver=new Train("Liege","RB26DET",15,500,0);
        Boat boatDriver=new Boat("Monaco",20,0);
        
        System.out.println("BUS DETAILS: ");
        System.out.println("Bus route number: "+busDriver.getRouteNumber()
                +"\nBus next stop: "+busDriver.getNextStopNumber()
                +"\nCapacity: "+busDriver.getTransCapacity()
                +"\nPassengers: "+busDriver.getNumberPassengers());
        System.out.println();
        
        System.out.println("TRAIN DETAILS: ");
        System.out.println("Next Station: "+trainDriver.getNameNextStation()
                +"\nNumber carriages: "+trainDriver.getNumberCarriages()
                +"\nEngine Type: "+trainDriver.getEngineType()
                +"\nCapacity: "+trainDriver.getTransCapacity()
                +"\nPassengers: "+trainDriver.getPassengerT());
        System.out.println();
        
        System.out.println("Boat next destination is: "+boatDriver.getNamePort()
                +"\nCapacity: "+boatDriver.getTransCapacity()
                +"\nPassengers: "+boatDriver.getPassengerB());
        System.out.println();
        
        Scanner reader=new Scanner(System.in);
        System.out.print("Enter integer number of additional passengers: ");
        int add=reader.nextInt();
        System.out.print("Bus new passenger count for getOn is: ");
		
        busDriver.getOn(add);
        System.out.print("Bus new passenger count for getOff is: ");
        busDriver.getOff(add);
        System.out.print("Train new passenger count for getOn is: ");
        trainDriver.getOn(add);
        System.out.print("Boat new passenger count for getOn is: ");
        boatDriver.getOn(add);
        System.out.println();
        
        System.out.print("Enter integer number of Bus next stop: ");
        int bsn=reader.nextInt();
        busDriver.setStopNumber(bsn);
        System.out.println("BUS DETAILS: ");
        System.out.println("Bus route number: "+busDriver.getRouteNumber());
        System.out.println("Bus next stop: "+busDriver.getNextStopNumber());
        System.out.println("Capacity: "+busDriver.getTransCapacity());
        System.out.println("Passengers: "+busDriver.getNumberPassengers());
        System.out.println();
        
        System.out.println("Enter name of Train next station: ");
        String nameS=reader.nextLine();
        trainDriver.setNameStation(nameS);
        System.out.println("TRAIN DETAILS: ");
        System.out.println("Next Station: "+trainDriver.getNameNextStation()
                +"\nNumber carriages: "+trainDriver.getNumberCarriages()
                +"\nEngine Type: "+trainDriver.getEngineType()
                +"\nCapacity: "+trainDriver.getTransCapacity()
                +"\nPassengers: "+trainDriver.getPassengerT());
        System.out.println();
        
        System.out.print("Enter name of Boat next port: ");
        String nport=reader.nextLine();
        boatDriver.setNameNextPort(nport);
        System.out.println("Boat next destination is: "+boatDriver.getNamePort()
                +"\nCapacity: "+boatDriver.getTransCapacity()
                +"\nPassengers: "+boatDriver.getPassengerB());
        
        System.out.println();
        System.out.println(busDriver.toString());
        System.out.println(trainDriver.toString());
        System.out.println(boatDriver.toString());
        
        System.out.println();
        System.out.println("Bus next stop");
        printDestination(busDriver);
        System.out.println("Train next station");
        printDestination(trainDriver);
        System.out.println("Boat next port");
        printDestination(boatDriver);
    }
    
    public static void printDestination(Transport Obj)
    {
        //Transport.getDestination(Obj);
        System.out.println(Transport.getDestination(Obj));
    }
}
