import java.util.ArrayList;
import java.util.List;
import java.util.function.Predicate;

public class CollectionPropertyCounter {

    // Generic method to count elements based on a specific property
    public static <T> int countByProperty(List<T> collection, Predicate<T> property) {
        int count = 0;
        for (T element : collection) {
            if (property.test(element)) {
                count++;
            }
        }
        return count;
    }

    // Utility method to check if a number is prime
    public static boolean isPrime(int num) {
        if (num < 2) return false;
        for (int i = 2; i <= Math.sqrt(num); i++) {
            if (num % i == 0) return false;
        }
        return true;
    }

    // Utility method to check if a number is a palindrome
    public static boolean isPalindrome(int num) {
        String str = String.valueOf(num);
        return str.equals(new StringBuilder(str).reverse().toString());
    }

    public static void main(String[] args) {
        // Create a collection of integers
        List<Integer> numbers = new ArrayList<>();
        numbers.add(11);
        numbers.add(22);
        numbers.add(3);
        numbers.add(44);
        numbers.add(121);
        numbers.add(7);
        numbers.add(8);

        // Count even numbers
        int evenCount = countByProperty(numbers, num -> num % 2 == 0);
        System.out.println("Even numbers count: " + evenCount);

        // Count odd numbers
        int oddCount = countByProperty(numbers, num -> num % 2 != 0);
        System.out.println("Odd numbers count: " + oddCount);

        // Count prime numbers
        int primeCount = countByProperty(numbers, CollectionPropertyCounter::isPrime);
        System.out.println("Prime numbers count: " + primeCount);

        // Count palindrome numbers
        int palindromeCount = countByProperty(numbers, CollectionPropertyCounter::isPalindrome);
        System.out.println("Palindrome numbers count: " + palindromeCount);
    }
}
