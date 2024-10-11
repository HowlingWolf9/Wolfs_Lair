abstract class Shape {
    abstract void numberOfSides();
}

class Triangle extends Shape {
    void numberOfSides() {
        System.out.println("number of sides = 3");
    }
}

class Rectangle extends Shape {
    void numberOfSides() {
        System.out.println("number of sides = 4");
    }
}

class Hexagon extends Shape {
    void numberOfSides() {
        System.out.println("number of sides = 6");
    }
}

class Main {    
    public static void main(String[] args) {
        Triangle triangle = new Triangle();
        triangle.numberOfSides();
        Rectangle rectangle = new Rectangle();
        rectangle.numberOfSides();
        Hexagon hexagon = new Hexagon();
        hexagon.numberOfSides();
    }
}