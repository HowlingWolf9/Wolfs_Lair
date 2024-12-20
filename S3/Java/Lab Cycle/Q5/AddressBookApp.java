/*
Experiment: 5

AIM: Create address book (name mob number)
You are tasked with creating a simple contact book application in Java. The application should be able to add new contacts, search for contacts by name, and display all contacts. The contacts should be stored in a text file named contacts.txt. Each contact should have a name and a phone number. A menu driven program.

ALGORITHM:
Save contacts in file contact.txt in the format name:contact_number
Define class person
Define class AddressBook
The constructor of AddressBook will read contact.txt line by line to a variable s
The line in s will be split based on delimiter into an array of strings, arrOfStr
From the data stored in arrOfStr, create an object of Person and store in array p
Keep a count of persons in variable count
Display details of persons from the array
Add a new contact
Read name and contact number
Create new person object and keep in array p
Contacts will be written to contact.txt when exiting the program
Delete a contact
Read a part of name and search in p for this piece of text
On finding a person with this text as a part of name in array p
Move all the persons right to this contact ,one position left
Search a contact
Read a part of name and search in p for this piece of text
On finding a person with this text as a part of name in array
    Print “found”
Save contact list
It is done when exiting the program
Take person objects one by one from array p
    Define a String variable newString
    newString=”Name of person:contactNumber”
    Write newString to the file contact.txt
*/
//CODE:
import java.io.*;
import java.util.Scanner;

class Person {
    String name;
    String phone;

    Person() {
        name = "";
        phone = "";
    }

    Person(String name, String phone) {
        this.name = name;
        this.phone = phone;
    }

    void print() {
        System.out.println("Name: " + name + ", Phone: " + phone);
    }
}

class AddressBook {
    Person p[] = new Person[100];
    int count = 0;

    AddressBook() {
        String path = "contacts.txt";
        File file = new File(path);
        // Check if the file exists; create it if it doesn't
        try {
            if (!file.exists()) {
                file.createNewFile();
            }
            Scanner sc = new Scanner(file);
            while (sc.hasNextLine()) {
                String s = sc.nextLine();
                String[] arrOfStr = s.split(":");
                p[count] = new Person(arrOfStr[0], arrOfStr[1]);
                count++;
            }
            sc.close();
        } catch (Exception e) {
            System.out.println("Error reading contacts: " + e.getMessage());
        }
    }// End constructor

    void printAll() {
        if (count == 0) {
            System.out.println("No contacts available.");
            return;
        }
        for (int i = 0; i < count; i++) {
            p[i].print();
        }
    }

    void add() {
        Scanner scan = new Scanner(System.in);
        System.out.print("Enter name: ");
        String tmpName = scan.nextLine();
        System.out.print("Enter phone: ");
        String tmpPhone = scan.nextLine();
        p[count] = new Person(tmpName, tmpPhone);
        count++;
        System.out.println("Contact added successfully.");
    }

    void delete() {
        Scanner scan = new Scanner(System.in);
        System.out.print("Enter the name of the contact to delete: ");
        String tmpName = scan.nextLine();
        boolean found = false;
        int indexToDelete = -1;
        for (int j = 0; j < count; j++) {
            if (p[j].name.toLowerCase().contains(tmpName.toLowerCase())) {
                p[j].print();
                found = true;
                indexToDelete = j;
                break;
            }
        }
        if (found) {
            System.out.print("Are you sure you want to delete this contact? (yes/no): ");
            String confirm = scan.nextLine();
            if (confirm.equalsIgnoreCase("yes")) {
                for (int j = indexToDelete; j < count - 1; j++) {
                    p[j] = p[j + 1];
                }
                p[count - 1] = null; // Clear the last element
                count--;
                System.out.println("Contact deleted successfully.");
            } else {
                System.out.println("Delete operation canceled.");
            }
        } else {
            System.out.println("Contact not found.");
        }
    }

    void exitPgm() {
        try {
            FileWriter fw = new FileWriter("contacts.txt");
            for (int j = 0; j < count; j++) {
                String newString = p[j].name + ":" + p[j].phone + System.lineSeparator();
                fw.write(newString);
            }
            fw.close();
            System.out.println("Contacts saved successfully.");
        } catch (Exception e) {
            System.out.println("Error saving contacts: " + e.getMessage());
        }
    }

    void search() {
        Scanner scan = new Scanner(System.in);
        System.out.print("Enter name of the person: ");
        String tmpName = scan.nextLine();
        boolean found = false;
        for (int j = 0; j < count; j++) {
            if (p[j].name.toLowerCase().contains(tmpName.toLowerCase())) {
                p[j].print();
                found = true;
            }
        }
        if (!found) {
            System.out.println("Contact not found.");
        }
    }
}

public class AddressBookApp {
    public static void main(String[] args) {
        AddressBook ad1 = new AddressBook();
        Scanner sc = new Scanner(System.in);
        int choice;
        while (true) {
            System.out.println("Enter your choice:");
            System.out.print("[1-Print All Contacts, 2-Add, 3-Search, 4-Delete, 5-Exit]: ");
            choice = sc.nextInt();
            sc.nextLine(); // consume the newline
            switch (choice) {
                case 1:
                    ad1.printAll();
                    break;
                case 2:
                    ad1.add();
                    break;
                case 3:
                    ad1.search();
                    break;
                case 4:
                    ad1.delete();
                    break;
                case 5:
                    ad1.exitPgm();
                    System.exit(0);
                default:
                    System.out.println("Your choice is wrong.");
            }
        }
    }
}