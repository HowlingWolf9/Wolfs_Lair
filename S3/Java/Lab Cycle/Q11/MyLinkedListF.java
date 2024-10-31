class Student {
    public String name;
    public String admno;

    Student() {
        this.name = "--------";
        this.admno = "---------";
    }

    Student(String name, String admno) {
        this.name = name;
        this.admno = admno;
    }

    public void display() {
        System.out.println("NAME: " + this.name);
        System.out.println("ADMNO: " + this.admno);
        System.out.println("--------------------------------");
    }
}

class Node {
    public Student stud;
    public Node link;

    Node() {
        this.stud = null;
        this.link = null;
    }

    Node(Student s) {
        stud = s;
        link = null;
    }
}

class LinkedList {
    public Node head;
    boolean found = false;

    LinkedList() {
        head = null;
    }

    public void addLast(Node newNode) {
        // add the new node as the last node in the linked list
        if (head == null) // No nodes in linked list
        {
            head = newNode;
        } else {
            // find last node and add at the end of list
            Node ptr;
            ptr = head;
            while (ptr.link != null) {
                ptr = ptr.link;
            }
            // ptr points the last node
            ptr.link = newNode;
            System.out.println("%%%%%%%%%%%Added data a end of list%%%%%%%%%");
        }
    }

    public void printLinkedList() {
        Node ptr;
        if (head == null) {
            System.out.println("No linked list exist");
        } else {
            ptr = head;
            while (ptr != null) {
                ptr.stud.display();
                ptr = ptr.link;
            }
        }
    }

    public void delete(String key) {
        Node ptr, prevNode;
        prevNode = null;
        if (head == null) {
            System.out.println("No linked list exist");
        } else {
            ptr = head;
            while (ptr != null) {
                if (ptr.stud.admno.equals(key)) {
                    System.out.println("Found Admission Number:" + key);
                    ptr.stud.display();
                    found = true;
                    break; // stop search
                }
                prevNode = ptr;
                ptr = ptr.link;
            }
            if (found == true) {
                System.out.println("Deleting this record with Admission number:" + key);
                // ptr points the node to be deleted
                // prevNode points the node preceding ptr
                // set the link field of prevNode = ptr.link
                if (ptr == head) {// Trying to delete head node
                    head = ptr.link; // make next node as head of list
                } else {
                    prevNode.link = ptr.link;
                }
                System.out.println("*********New List********");
                printLinkedList();
            }
        }
        if (found == false) {
            System.out.println("Record not found with Admission number:" + key);
        }
    }

    public void search(String key) {
        Node ptr;
        if (head == null) {
            System.out.println("No linked list exist");
        } else {
            ptr = head;
            while (ptr != null) {
                if (ptr.stud.admno.equals(key)) {
                    System.out.println("Found Admission Number:" + key);
                    ptr.stud.display();
                    found = true;
                    break; // stop search
                }
                ptr = ptr.link;
            }
            if (found == false) {
                System.out.println("Record not found with Admission number:" + key);
            }
        }
    }
}// End class linked list

public class MyLinkedListF {
    public static void main(String arg[]) {
        LinkedList ll = new LinkedList();
        Node newNode;
        Student s1 = new Student("SAM", "BB45");
        newNode = new Node(s1);
        ll.addLast(newNode);
        Student s2 = new Student("JOHN", "BB46");
        newNode = new Node(s2);
        ll.addLast(newNode);
        Student s3 = new Student("DAVID", "BB47");
        newNode = new Node(s3);
        ll.addLast(newNode);
        Student s4 = new Student("FREDDY", "BB48");
        newNode = new Node(s4);
        ll.addLast(newNode);
        ll.printLinkedList();
        ll.search("BB90");
        ll.search("BB47");
        ll.delete("BB46");
        ll.delete("BB48");
        Student s5 = new Student("DON", "BB49");
        newNode = new Node(s5);
        ll.addLast(newNode);
        ll.delete("BB45");
    }
}