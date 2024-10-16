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
                int value3 = Integer.parseInt(parts[3]);
                int sum = value1 + value2 + value3;

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