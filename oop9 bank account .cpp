// BankAccount class representing an individual account
class BankAccount {
    private String accountHolder;
    private String accountNumber;
    private double balance;

    // Constructor to initialize the account details
    public BankAccount(String accountHolder, String accountNumber, double initialDeposit) {
        this.accountHolder = accountHolder;
        this.accountNumber = accountNumber;
        this.balance = initialDeposit;
    }

    // Method to deposit money
    public void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            System.out.println("Deposited: $" + amount);
        } else {
            System.out.println("Invalid deposit amount.");
        }
    }

    // Method to withdraw money
    public void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            System.out.println("Withdrew: $" + amount);
        } else {
            System.out.println("Invalid withdrawal amount or insufficient balance.");
        }
    }

    // Method to display account information
    public void displayAccountInfo() {
        System.out.println("\nAccount Holder: " + accountHolder);
        System.out.println("Account Number: " + accountNumber);
        System.out.println("Account Balance: $" + balance);
    }
}

// Main class to run the Banking System
public class BankingSystem {

    public static void main(String[] args) {
        // Creating a new BankAccount object
        BankAccount account = new BankAccount("John Doe", "123456789", 500.0);

        // Displaying initial account information
        account.displayAccountInfo();

        // Performing operations
        account.deposit(200.0);   // Depositing money
        account.withdraw(100.0);  // Withdrawing money
        account.displayAccountInfo();  // Displaying account information again

        // Trying to withdraw more than the balance
        account.withdraw(700.0);
        account.displayAccountInfo();
    }
}
