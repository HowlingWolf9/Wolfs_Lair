class Employee {
    String name;
    String address;
    int age;
    int salary;

    Employee(String name, String address, int age, int salary) {
        this.name = name;
        this.address = address;
        this.age = age;
        this.salary = salary;
    }

    void printSalary() {
        System.out.println("Salary: " + salary);
    }
}

class Officer extends Employee {
    String specialization;

    Officer(String name, String address, int age, int salary, String specialization) {
        super(name, address, age, salary);
        this.specialization = specialization;
    }

    void printDetails() {
        System.out.println("Name: " + name);
        System.out.println("Address: " + address);
        System.out.println("Age: " + age);
        System.out.println("Specialization: " + specialization);
    }
}

class Manager extends Employee {
    String department;

    Manager(String name, String address, int age, int salary, String department) {
        super(name, address, age, salary);
        this.department = department;      
    }

    void printDetails() {
        System.out.println("Name: " + name);
        System.out.println("Address: " + address);
        System.out.println("Age: " + age);
        System.out.println("Department: " + department);
    }
}

class Main {
    public static void main(String[] args) {
        Officer o = new Officer("John", "123 Main St", 30, 50000, "Law");
        Manager m = new Manager("Jane", "456 Oak St", 35, 80000, "Finance");
        System.out.println("Employee Details:");
        System.out.println("\nOfficer Details:");
        o.printDetails();
        o.printSalary();
        System.out.println("\nManager Details:");
        m.printDetails();
        m.printSalary();
    }
}
