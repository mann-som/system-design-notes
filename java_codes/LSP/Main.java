package java_codes;

import java.util.ArrayList;
import java.util.List;

public class Main {

    public static class Vehicle {
        public Integer getNumOfTyres(){
            return 2;
        }
        public Boolean hasEngine(){
            return true;
        }
    }

    public static class MotorCycle extends Vehicle {
    }

    public static class Car extends Vehicle {
        @Override
        public Integer getNumOfTyres(){
            return 4;
        }
    }

    public static void main(String[] args) {
        List<Vehicle> vehicleList = new ArrayList<>();
        vehicleList.add(new MotorCycle());
        vehicleList.add(new Car());

        for(Vehicle vehicle : vehicleList){
            System.out.println("Has Engine: " + vehicle.hasEngine());
            System.out.println("Tyres: " + vehicle.getNumOfTyres());
        }
    }
}

/*
this method doesn't follow LSP.
what will?

a class -> vehicle with just generic method, like number of tyres (ofc every vehicle have typres), for every other class that will inherit it
a seperate class like engineVehicle which will inherit vehicle class and add specific methods

 */