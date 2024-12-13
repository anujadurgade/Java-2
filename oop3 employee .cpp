// Base class: Employee
class Employee {
    String empName;
    int empId;
    String address;
    String mailId;
    String mobileNo;

    // Constructor for Employee class
    public Employee(String empName, int empId, String address, String mailId, String mobileNo) {
        this.empName = empName;
        this.empId = empId;
        this.address = address;
        this.mailId = mailId;
        this.mobileNo = mobileNo;
    }
}

// Subclass: Programmer
class Programmer extends Employee {
    double basicPay;

    // Constructor
    public Programmer(String empName, int empId, String address, String mailId, String mobileNo, double basicPay) {
        super(empName, empId, address, mailId, mobileNo);
        this.basicPay = basicPay;
    }

    // Method to calculate salary
    public void calculateSalary() {
        double da = 0.97 * basicPay; // 97% of BP
        double hra = 0.10 * basicPay; // 10% of BP
        double pf = 0.12 * basicPay; // 12% of BP
        double staffClubFund = 0.001 * basicPay; // 0.1% of BP
        double grossSalary = basicPay + da + hra;
        double netSalary = grossSalary - (pf + staffClubFund);

        System.out.println("Pay Slip for Programmer:");
        System.out.println("Gross Salary: " + grossSalary);
        System.out.println("Net Salary: " + netSalary);
    }
}

// Subclass: TeamLead
class TeamLead extends Programmer {
    // Constructor
    public TeamLead(String empName, int empId, String address, String mailId, String mobileNo, double basicPay) {
        super(empName, empId, address, mailId, mobileNo, basicPay);
    }

    @Override
    public void calculateSalary() {
        super.calculateSalary();
        System.out.println("Position: Team Lead\n");
    }
}

// Subclass: Assistant Project Manager
class AssistantProjectManager extends Programmer {
    // Constructor
    public AssistantProjectManager(String empName, int empId, String address, String mailId, String mobileNo, double basicPay) {
        super(empName, empId, address, mailId, mobileNo, basicPay);
    }

    @Override
    public void calculateSalary() {
        super.calculateSalary();
        System.out.println("Position: Assistant Project Manager\n");
    }
}

// Subclass: Project Manager
class ProjectManager extends Programmer {
    // Constructor
    public ProjectManager(String empName, int empId, String address, String mailId, String mobileNo, double basicPay) {
        super(empName, empId, address, mailId, mobileNo, basicPay);
    }

    @Override
    public void calculateSalary() {
        super.calculateSalary();
        System.out.println("Position: Project Manager\n");
    }
}

// Main class
public class EmployeeTest {
    public static void main(String[] args) {
        // Create instances of each subclass and calculate salary
        Programmer programmer = new Programmer("Alice", 101, "123 Street", "alice@mail.com", "9876543210", 50000);
        programmer.calculateSalary();

        TeamLead teamLead = new TeamLead("Bob", 102, "456 Street", "bob@mail.com", "9876543211", 70000);
        teamLead.calculateSalary();

        AssistantProjectManager apm = new AssistantProjectManager("Charlie", 103, "789 Street", "charlie@mail.com", "9876543212", 90000);
        apm.calculateSalary();

        ProjectManager pm = new ProjectManager("David", 104, "101 Street", "david@mail.com", "9876543213", 120000);
        pm.calculateSalary();
    }
}
