// Vehicle Interface
interface Vehicle {
    void changeGear(int gear);
    void speedUp(int increment);
    void applyBrakes(int decrement);
}

// Bicycle Class
class Bicycle implements Vehicle {
    private int speed;
    private int gear;

    // Constructor
    public Bicycle() {
        this.speed = 0;
        this.gear = 1;
    }

    @Override
    public void changeGear(int gear) {
        this.gear = gear;
        System.out.println("Bicycle gear changed to: " + this.gear);
    }

    @Override
    public void speedUp(int increment) {
        this.speed += increment;
        System.out.println("Bicycle speed increased to: " + this.speed + " km/h");
    }

    @Override
    public void applyBrakes(int decrement) {
        this.speed -= decrement;
        if (this.speed < 0) this.speed = 0;
        System.out.println("Bicycle speed decreased to: " + this.speed + " km/h");
    }
}

// Bike Class
class Bike implements Vehicle {
    private int speed;
    private int gear;

    // Constructor
    public Bike() {
        this.speed = 0;
        this.gear = 1;
    }

    @Override
    public void changeGear(int gear) {
        this.gear = gear;
        System.out.println("Bike gear changed to: " + this.gear);
    }

    @Override
    public void speedUp(int increment) {
        this.speed += increment;
        System.out.println("Bike speed increased to: " + this.speed + " km/h");
    }

    @Override
    public void applyBrakes(int decrement) {
        this.speed -= decrement;
        if (this.speed < 0) this.speed = 0;
        System.out.println("Bike speed decreased to: " + this.speed + " km/h");
    }
}

// Car Class
class Car implements Vehicle {
    private int speed;
    private int gear;

    // Constructor
    public Car() {
        this.speed = 0;
        this.gear = 1;
    }

    @Override
    public void changeGear(int gear) {
        this.gear = gear;
        System.out.println("Car gear changed to: " + this.gear);
    }

    @Override
    public void speedUp(int increment) {
        this.speed += increment;
        System.out.println("Car speed increased to: " + this.speed + " km/h");
    }

    @Override
    public void applyBrakes(int decrement) {
        this.speed -= decrement;
        if (this.speed < 0) this.speed = 0;
        System.out.println("Car speed decreased to: " + this.speed + " km/h");
    }
}

// Main Class
public class VehicleTest {
    public static void main(String[] args) {
        // Create instances of each vehicle
        Vehicle bicycle = new Bicycle();
        Vehicle bike = new Bike();
        Vehicle car = new Car();

        // Test Bicycle
        System.out.println("Testing Bicycle:");
        bicycle.changeGear(2);
        bicycle.speedUp(10);
        bicycle.applyBrakes(5);

        // Test Bike
        System.out.println("\nTesting Bike:");
        bike.changeGear(3);
        bike.speedUp(20);
        bike.applyBrakes(10);

        // Test Car
        System.out.println("\nTesting Car:");
        car.changeGear(4);
        car.speedUp(60);
        car.applyBrakes(20);
    }
}
