import java.io.*;
import java.util.Scanner;

public class FileOperations {
    static String FILE_NAME = "file.txt";

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int choice;

        do {
            System.out.println("\nFile Operations Menu:");
            System.out.println("1. Create a File");
            System.out.println("2. Write Data to File");
            System.out.println("3. Read from File");
            System.out.println("4. Delete File");
            System.out.println("5. Count Words in File");
            System.out.println("6. Exit");
            System.out.print("Enter your choice: ");
            choice = scanner.nextInt();
            scanner.nextLine();

            switch (choice) {
                case 1:
                    createFile();
                    break;
                case 2:
                    writeFile(scanner);
                    break;
                case 3:
                    readFile();
                    break;
                case 4:
                    deleteFile();
                    break;
                case 5:
                    countWordsInFile();
                    break;
                case 6:
                    System.out.println("Exiting...");
                    break;
                default:
                    System.out.println("Invalid choice. Please try again.");
            }
        } while (choice != 6);

        scanner.close();
    }

    static void createFile() {
        try {
            File file = new File(FILE_NAME);
            if (file.createNewFile()) {
                System.out.println("File created successfully.");
            } else {
                System.out.println("File already exists.");
            }
        } catch (IOException e) {
            System.err.println("An error occurred while creating the file: " + e.getMessage());
        }
    }

    static void writeFile(Scanner scanner) {
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(FILE_NAME, true))) {
            System.out.println("Enter the data to write to the file:");
            String data = scanner.nextLine();
            writer.write(data);
            writer.newLine();
            System.out.println("Data written to file successfully.");
        } catch (IOException e) {
            System.err.println("An error occurred while writing to the file: " + e.getMessage());
        }
    }

    static void readFile() {
        try (BufferedReader reader = new BufferedReader(new FileReader(FILE_NAME))) {
            String line;
            System.out.println("File contents:");
            while ((line = reader.readLine()) != null) {
                System.out.println(line);
            }
        } catch (IOException e) {
            System.err.println("An error occurred while reading the file: " + e.getMessage());
        }
    }

    static void deleteFile() {
        File file = new File(FILE_NAME);
        if (file.delete()) {
            System.out.println("File deleted successfully.");
        } else {
            System.out.println("Failed to delete the file.");
        }
    }

    static void countWordsInFile() {
        try (BufferedReader reader = new BufferedReader(new FileReader(FILE_NAME))) {
            String line;
            int wordCount = 0;
            while ((line = reader.readLine()) != null) {
                String[] words = line.split("\\s+");
                wordCount += words.length;
            }
            System.out.println("The file contains " + wordCount + " words.");
        } catch (IOException e) {
            System.err.println("An error occurred while counting words in the file: " + e.getMessage());
        }
    }
}
