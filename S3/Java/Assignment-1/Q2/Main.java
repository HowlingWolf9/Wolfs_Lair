class Employee {
    protected String name;
    protected double salary;

    public Employee(String name, double salary) {
        this.name = name;
        this.salary = salary;
    }

    public double calculateBonus() {
        return 0; // No bonus for a generic employee
    }

    public void displayDetails() {
        System.out.println("Employee Name: " + name);
        System.out.println("Base Salary: " + salary);
        System.out.println("Bonus: " + calculateBonus());
    }
}

class Manager extends Employee {
    private static final double FIXED_BONUS = 5000;

    public Manager(String name, double salary) {
        super(name, salary);
    }

    public double calculateBonus() {
        return FIXED_BONUS;
    }
}

class Developer extends Employee {
    private double performanceRating;

    public Developer(String name, double salary, double performanceRating) {
        super(name, salary);
        this.performanceRating = performanceRating;
    }

    public double calculateBonus() {
        return salary * performanceRating * 0.1;
    }
}

public class Main {
    public static void main(String[] args) {
        Employee[] employees = new Employee[3];
        employees[0] = new Manager("Devadath", 80000);
        employees[1] = new Developer("Athul", 60000, 4.5);
        employees[2] = new Developer("Shibu", 55000, 3.8);
        System.out.println("Bonus Details:");
        for (Employee emp : employees) {
            emp.displayDetails();
            System.out.println();
        }
    }
}
