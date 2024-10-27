import java.io.*;
import java.util.*;

public class DSVProcessor {

    public static void main(String[] args) {
        List<String> ids = new ArrayList<>();
        List<Integer> sums = new ArrayList<>();

        try (BufferedReader reader = new BufferedReader(new FileReader("data-roll.txt"))) {
            String line;
            while ((line = reader.readLine()) != null) {
                String[] parts = line.split(":");
                String id = parts[0];
                int value1 = Integer.parseInt(parts[1]);
                int value2 = Integer.parseInt(parts[2]);
                int sum = value1 + value2;

                int index = ids.indexOf(id);
                if (index != -1) {
                    sums.set(index, sums.get(index) + sum);
                } else {
                    ids.add(id);
                    sums.add(sum);
                }
            }
        } catch (IOException e) {
            System.err.println("Error reading the input file: " + e.getMessage());
        }

        try (BufferedWriter writer = new BufferedWriter(new FileWriter("op-roll.txt"))) {
            for (int i = 0; i < ids.size(); i++) {
                writer.write(ids.get(i) + ":" + sums.get(i));
                writer.newLine();
            }
        } catch (IOException e) {
            System.err.println("Error writing to the output file: " + e.getMessage());
        }
    }
}

/*
ALGORITHM: DSVProcessor
INPUT: data-roll.txt
OUTPUT: op-roll.txt

1. Read the textfile in which the id and its valaues are stored
2. Lines are in the format of id:value1:value2
    AB100:10:20
    AB100:20:5
    AB100:11:100
3. Split the line into id, value1, value2 using ":" as the delimiter
4. Calculate the sum of value1, value2
5. Store the id and the sum in a list
6. If the id is already present in the list, add the sum to the existing value
7. Write the list to the output file in the format of id:sum
*/
