import java.io.*;
import java.util.Scanner;

public class ContactBook {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int choice;
        do {
            System.out.println("Contact Book Menu");
            System.out.println("1. Add a Contact");
            System.out.println("2. Search for a Contact");
            System.out.println("3. Display All Contacts");
            System.out.println("4. Exit");
            System.out.print("Enter your choice: ");
            choice = scanner.nextInt();
            scanner.nextLine();

            switch (choice) {
                case 1:
                    addContact(scanner);
                    break;
                case 2:
                    searchContact(scanner);
                    break;
                case 3:
                    displayContacts();
                    break;
                case 4:
                    System.out.println("Exiting...");
                    break;
                default:
                    System.out.println("Invalid choice. Please try again.");
            }
        } while (choice != 4);

        scanner.close();
    }

    private static void addContact(Scanner scanner) {
        System.out.print("Enter the name of the contact: ");
        String name = scanner.nextLine();
        System.out.print("Enter the phone number of the contact: ");
        String phoneNumber = scanner.nextLine();

        try {
            BufferedWriter writer = new BufferedWriter(new FileWriter("contacts.txt", true));
            writer.write(name + ": " + phoneNumber);
            writer.newLine();
            writer.close();
            System.out.println("Contact added successfully.");
        } catch (IOException e) {
            System.out.println("Error adding contact: " + e.getMessage());
        }
    }

    private static void searchContact(Scanner scanner) {
        System.out.print("Enter the name of the contact to search for: ");
        String searchName = scanner.nextLine();

        try {
            BufferedReader reader = new BufferedReader(new FileReader("contacts.txt"));
            String line;
            boolean found = false;
            while ((line = reader.readLine()) != null) {
                String[] parts = line.split(": ");
                if (parts[0].equals(searchName)) {
                    System.out.println("Contact found: " + line);
                    found = true;
                    break;
                }
            }
            reader.close();
            if (!found) {
                System.out.println("Contact not found.");
            }
        } catch (IOException e) {
            System.out.println("Error searching for contact: " + e.getMessage());
        }
    }

    private static void displayContacts() {
        try {
            BufferedReader reader = new BufferedReader(new FileReader("contacts.txt"));
            String line;
            while ((line = reader.readLine()) != null) {
                System.out.println(line);
            }
            reader.close();
        } catch (IOException e) {
            System.out.println("Error displaying contacts: " + e.getMessage());
        }
    }
}