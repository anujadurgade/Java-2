// Abstract class Car
abstract class Car {
    public abstract void allocateAccessories();
    public abstract void assembleParts();
    public abstract void finalMakeup();

    public void buildCar() {
        allocateAccessories();
        assembleParts();
        finalMakeup();
        System.out.println("Car build complete.\n");
    }
}

// Hatchback class
class Hatchback extends Car {
    @Override
    public void allocateAccessories() {
        System.out.println("Allocating accessories for Hatchback...");
    }

    @Override
    public void assembleParts() {
        System.out.println("Assembling parts for Hatchback...");
    }

    @Override
    public void finalMakeup() {
        System.out.println("Final makeup for Hatchback completed.");
    }
}

// Sedan class
class Sedan extends Car {
    @Override
    public void allocateAccessories() {
        System.out.println("Allocating accessories for Sedan...");
    }

    @Override
    public void assembleParts() {
        System.out.println("Assembling parts for Sedan...");
    }

    @Override
    public void finalMakeup() {
        System.out.println("Final makeup for Sedan completed.");
    }
}

// SUV class
class SUV extends Car {
    @Override
    public void allocateAccessories() {
        System.out.println("Allocating accessories for SUV...");
    }

    @Override
    public void assembleParts() {
        System.out.println("Assembling parts for SUV...");
    }

    @Override
    public void finalMakeup() {
        System.out.println("Final makeup for SUV completed.");
    }
}

// CarFactory class (Factory class)
class CarFactory {
    public static Car createCar(String carType) {
        switch (carType.toUpperCase()) {
            case "HATCHBACK":
                return new Hatchback();
            case "SEDAN":
                return new Sedan();
            case "SUV":
                return new SUV();
            default:
                System.out.println("Invalid car type!");
                return null;
        }
    }
}

// Main class to test the Factory Pattern
public class TestFactoryPattern {
    public static void main(String[] args) {
        // Creating a Hatchback car using the CarFactory
        Car hatchback = CarFactory.createCar("Hatchback");
        if (hatchback != null) {
            hatchback.buildCar();
        }

        // Creating a Sedan car using the CarFactory
        Car sedan = CarFactory.createCar("Sedan");
        if (sedan != null) {
            sedan.buildCar();
        }

        // Creating an SUV car using the CarFactory
        Car suv = CarFactory.createCar("SUV");
        if (suv != null) {
            suv.buildCar();
        }
    }
}
