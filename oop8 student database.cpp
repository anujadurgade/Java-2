import java.io.*;
import java.util.Scanner;

public class StudentDatabase {
    private static final String DATABASE_FILE = "student_database.txt";

    // Method to create or append to the database
    public static void createDatabase() throws IOException {
        Scanner scanner = new Scanner(System.in);
        FileWriter writer = new FileWriter(DATABASE_FILE, true);

        System.out.print("Enter Roll Number: ");
        int rollNo = scanner.nextInt();
        scanner.nextLine(); // Consume the newline

        System.out.print("Enter Name: ");
        String name = scanner.nextLine();

        System.out.print("Enter Class: ");
        String studentClass = scanner.nextLine();

        System.out.print("Enter Marks: ");
        int marks = scanner.nextInt();

        // Append the record to the database file
        writer.write(rollNo + "," + name + "," + studentClass + "," + marks + "\n");
        writer.close();

        System.out.println("Record added successfully.");
    }

    // Method to display all records
    public static void displayDatabase() throws IOException {
        BufferedReader reader = new BufferedReader(new FileReader(DATABASE_FILE));
        String line;

        System.out.println("\n--- Student Records ---");
        while ((line = reader.readLine()) != null) {
            String[] data = line.split(",");
            System.out.println("Roll No: " + data[0] + ", Name: " + data[1] + ", Class: " + data[2] + ", Marks: " + data[3]);
        }
        reader.close();
    }

    // Method to clear all records
    public static void clearRecords() throws IOException {
        FileWriter writer = new FileWriter(DATABASE_FILE, false); // Overwrite the file
        writer.close();
        System.out.println("All records cleared.");
    }

    // Method to search for a record by roll number
    public static void searchRecord(int rollNo) throws IOException {
        BufferedReader reader = new BufferedReader(new FileReader(DATABASE_FILE));
        String line;
        boolean found = false;

        while ((line = reader.readLine()) != null) {
            String[] data = line.split(",");
            if (Integer.parseInt(data[0]) == rollNo) {
                System.out.println("Record Found: Roll No: " + data[0] + ", Name: " + data[1] + ", Class: " + data[2] + ", Marks: " + data[3]);
                found = true;
                break;
            }
        }
        reader.close();

        if (!found) {
            System.out.println("Record not found.");
        }
    }

    // Method to modify a record by roll number
    public static void modifyRecord(int rollNo) throws IOException {
        File inputFile = new File(DATABASE_FILE);
        File tempFile = new File("temp_database.txt");

        BufferedReader reader = new BufferedReader(new FileReader(inputFile));
        BufferedWriter writer = new BufferedWriter(new FileWriter(tempFile));

        Scanner scanner = new Scanner(System.in);
        String line;
        boolean found = false;

        while ((line = reader.readLine()) != null) {
            String[] data = line.split(",");
            if (Integer.parseInt(data[0]) == rollNo) {
                found = true;

                System.out.print("Enter New Name: ");
                String newName = scanner.nextLine();

                System.out.print("Enter New Class: ");
                String newClass = scanner.nextLine();

                System.out.print("Enter New Marks: ");
                int newMarks = scanner.nextInt();
                scanner.nextLine(); // Consume newline

                writer.write(rollNo + "," + newName + "," + newClass + "," + newMarks + "\n");
                System.out.println("Record modified successfully.");
            } else {
                writer.write(line + "\n");
            }
        }
        reader.close();
        writer.close();

        // Replace original file with updated file
        if (!inputFile.delete()) {
            System.out.println("Could not delete original file.");
        }
        if (!tempFile.renameTo(inputFile)) {
            System.out.println("Could not rename temp file.");
        }

        if (!found) {
            System.out.println("Record not found.");
        }
    }

    // Main method
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        while (true) {
            System.out.println("\n--- Student Database Management ---");
            System.out.println("1. Create Database");
            System.out.println("2. Display Database");
            System.out.println("3. Clear Records");
            System.out.println("4. Modify Record");
            System.out.println("5. Search Record");
            System.out.println("6. Exit");
            System.out.print("Enter your choice: ");

            int choice = scanner.nextInt();

            try {
                switch (choice) {
                    case 1:
                        createDatabase();
                        break;
                    case 2:
                        displayDatabase();
                        break;
                    case 3:
                        clearRecords();
                        break;
                    case 4:
                        System.out.print("Enter Roll Number to Modify: ");
                        int rollNoToModify = scanner.nextInt();
                        modifyRecord(rollNoToModify);
                        break;
                    case 5:
                        System.out.print("Enter Roll Number to Search: ");
                        int rollNoToSearch = scanner.nextInt();
                        searchRecord(rollNoToSearch);
                        break;
                    case 6:
                        System.out.println("Exiting program.");
                        scanner.close();
                        return;
                    default:
                        System.out.println("Invalid choice. Please try again.");
                }
            } catch (IOException e) {
                System.out.println("An error occurred: " + e.getMessage());
            }
        }
    }
}
