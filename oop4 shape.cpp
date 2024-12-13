// Abstract Base Class: Shape
abstract class Shape {
    double dimension1, dimension2;

    // Method to input dimensions
    public void setDimensions(double d1, double d2) {
        this.dimension1 = d1;
        this.dimension2 = d2;
    }

    // Abstract method to calculate area
    abstract double area();
}

// Derived Class: Triangle
class Triangle extends Shape {
    // Override area() method
    @Override
    double area() {
        return 0.5 * dimension1 * dimension2; // Area = 0.5 * base * height
    }
}

// Derived Class: Rectangle
class Rectangle extends Shape {
    // Override area() method
    @Override
    double area() {
        return dimension1 * dimension2; // Area = length * breadth
    }
}

// Main Class
public class ShapeTest {
    public static void main(String[] args) {
        // Create objects for Triangle and Rectangle
        Shape triangle = new Triangle();
        Shape rectangle = new Rectangle();

        // Input dimensions for triangle
        triangle.setDimensions(10, 20); // Base = 10, Height = 20
        System.out.println("Area of Triangle: " + triangle.area());

        // Input dimensions for rectangle
        rectangle.setDimensions(15, 25); // Length = 15, Breadth = 25
        System.out.println("Area of Rectangle: " + rectangle.area());
    }
}
