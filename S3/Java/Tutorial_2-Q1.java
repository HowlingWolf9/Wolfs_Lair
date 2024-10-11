class ClassA {
    private int field1;
    public int field2;
}
class ClassB {
    void display() {
        ClassA obj = new ClassA();
        System.out.println(obj.field1); // What will happen here?
        System.out.println(obj.field2);
    }
    public static void main(String a[])
    {
        display();
    }
}