import java.util.Scanner;

public class ExceptionHandling {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        try {
            // Prompt user for input
            System.out.print("Enter the first number (Num1): ");
            String num1Str = scanner.nextLine();

            System.out.print("Enter the second number (Num2): ");
            String num2Str = scanner.nextLine();

            // Parse inputs to integers
            int num1 = Integer.parseInt(num1Str);
            int num2 = Integer.parseInt(num2Str);

            // Perform division
            int result = num1 / num2;
            System.out.println("Result of division: " + result);

        } catch (ArithmeticException e) {
            // Handle division by zero
            System.out.println("Arithmetic Exception: Division by zero is not allowed.");
        } catch (NumberFormatException e) {
            // Handle non-integer input
            System.out.println("Number Format Exception: Please enter valid integers.");
        } catch (ArrayIndexOutOfBoundsException e) {
            // Handle array index out of bounds (unlikely in this case but added for completeness)
            System.out.println("Array Index Out Of Bounds Exception: Invalid array access.");
        } finally {
            // Close the scanner resource
            scanner.close();
            System.out.println("Program execution completed.");
        }
    }
}
