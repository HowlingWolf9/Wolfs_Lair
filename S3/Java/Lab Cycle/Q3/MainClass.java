/*
Experiment: 3

AIM: Write a Java program which creates a class named 'Employee' having the following members: Name, Age, Phone number, Address, Salary. It also has a method named 'printSalary( )' which prints the salary of the Employee. Two classes 'Officer' and 'Manager' inherits the 'Employee' class. The 'Officer' and 'Manager' classes have data members 'specialization' and 'department' respectively. Now, assign name, age, phone number, address and salary to an officer and a manager by making an object of both of these classes and print the same. (Exercise to understand inheritance). ** 

ALGORITHM:
Define class Employee with public attributes Name and Age, private attributes PhoneNumber, Address and protected attribute Salary.
- Define constructor with attributes passed as parameters
- Define methods getPhoneNumber() and getAddress() to return PhoneNumber abd Address respectively

Define class Officer which inherits from Employee(using extends keyword) with public attribute Specialization.
- Define constructor
-- Pass the superclass attributes to the superclass constructor.Initialize the remaining attribute Specialization

Define class Manager which inherits from Employee(using extends keyword) with public attribute Department.
- Define constructor
-- Pass the superclass attributes to the superclass constructor.Initialize the remaining attribute Department

Define MainClass with main() method.
- Initialize Officer object officer
- Initialize Manager object manager
- Print details of officer and manager
*/
//CODE:
class Employee {
    public String Name;
    private String PhoneNumber;
    private String Address;
    protected double Salary;
    public int Age;

    public Employee(String Name, int Age, String PhoneNumber, String Address, double Salary) {
        this.Name = Name;
        this.Age = Age;
        this.PhoneNumber = PhoneNumber;
        this.Address = Address;
        this.Salary = Salary;
    }

    public String getPhoneNumber() {
        return PhoneNumber;
    }

    public String getAddress() {
        return Address;
    }
}

class Officer extends Employee {
    public String Specialization;

    public Officer(String Name, int Age, String PhoneNumber, String Address, double Salary, String Specialization) {
        super(Name, Age, PhoneNumber, Address, Salary);
        this.Specialization = Specialization;
    }
}

class Manager extends Employee {
    public String Department;

    public Manager(String Name, int Age, String PhoneNumber, String Address, double Salary, String Department) {
        super(Name, Age, PhoneNumber, Address, Salary);
        this.Department = Department;
    }
}

public class MainClass {
    public static void main(String[] args) {
        Officer officer = new Officer("John", 35, "1234567890", "123 Main St", 50000.0, "IT");
        Manager manager = new Manager("Alice", 40, "0987654321", "456 Elm St", 70000.0, "HR");

        System.out.println("Officer Details:");
        System.out.println("Name: " + officer.Name);
        System.out.println("Age: " + officer.Age);
        System.out.println("Phone Number: " + officer.getPhoneNumber());
        System.out.println("Address: " + officer.getAddress());
        System.out.println("Salary: " + officer.Salary);
        System.out.println("Specialization: " + officer.Specialization);
        
        System.out.println("\nManager Details:");
        System.out.println("Name: " + manager.Name);
        System.out.println("Age: " + manager.Age);
        System.out.println("Phone Number: " + manager.getPhoneNumber());
        System.out.println("Address: " + manager.getAddress());
        System.out.println("Salary: " + manager.Salary);
        System.out.println("Department: " + manager.Department);
    }
}