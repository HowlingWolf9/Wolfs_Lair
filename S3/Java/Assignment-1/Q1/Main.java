class Person {
    String name;
    int age;

    Person(String name, int age) {
        this.name = name;
        this.age = age;
    }

    void displayPersonDetails() {
        System.out.println("Name: " + name);
        System.out.println("Age: " + age);
    }
}

class Student extends Person {
    String studentId;

    Student(String name, int age, String studentId) {
        super(name, age);
        this.studentId = studentId;
    }

    void displayStudentDetails() {
        displayPersonDetails();
        System.out.println("Student ID: " + studentId);
    }
}

public class Main {
    public static void main(String[] args){
        Person person = new Person("Leo" , 39);
        Student student = new Student("Devadath", 18, "21");
        System.out.println("\nDetails of Person:");
        person.displayPersonDetails();
        System.out.println("\nDetails of Student:");
        student.displayStudentDetails();
    }
}
