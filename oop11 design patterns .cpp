// PaymentStrategy Interface (Strategy)
interface PaymentStrategy {
    void pay(double amount);
}

// Concrete Strategy 1: CreditCard Payment
class CreditCardPayment implements PaymentStrategy {
    private String cardNumber;

    public CreditCardPayment(String cardNumber) {
        this.cardNumber = cardNumber;
    }

    @Override
    public void pay(double amount) {
        System.out.println("Paying " + amount + " using Credit Card: " + cardNumber);
    }
}

// Concrete Strategy 2: PayPal Payment
class PayPalPayment implements PaymentStrategy {
    private String email;

    public PayPalPayment(String email) {
        this.email = email;
    }

    @Override
    public void pay(double amount) {
        System.out.println("Paying " + amount + " using PayPal account: " + email);
    }
}

// Concrete Strategy 3: Bitcoin Payment
class BitcoinPayment implements PaymentStrategy {
    private String walletAddress;

    public BitcoinPayment(String walletAddress) {
        this.walletAddress = walletAddress;
    }

    @Override
    public void pay(double amount) {
        System.out.println("Paying " + amount + " using Bitcoin wallet: " + walletAddress);
    }
}

// ShoppingCart class that uses PaymentStrategy
class ShoppingCart {
    private PaymentStrategy paymentStrategy;

    // Set payment strategy
    public void setPaymentStrategy(PaymentStrategy paymentStrategy) {
        this.paymentStrategy = paymentStrategy;
    }

    // Calculate and apply payment using the selected strategy
    public void checkout(double amount) {
        paymentStrategy.pay(amount);
    }
}

// TestStrategyPattern class to test the Strategy Pattern
public class TestStrategyPattern {
    public static void main(String[] args) {
        // Create a shopping cart
        ShoppingCart cart = new ShoppingCart();

        // Pay using Credit Card
        cart.setPaymentStrategy(new CreditCardPayment("1234-5678-9876-5432"));
        cart.checkout(100.50);

        System.out.println();

        // Pay using PayPal
        cart.setPaymentStrategy(new PayPalPayment("user@example.com"));
        cart.checkout(200.75);

        System.out.println();

        // Pay using Bitcoin
        cart.setPaymentStrategy(new BitcoinPayment("1A1zP1eP5QGefi2DMPTfTL5SLmv7DivfNa"));
        cart.checkout(300.20);
    }
}
