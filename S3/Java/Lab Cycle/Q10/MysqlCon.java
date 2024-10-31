/*
Experiment: 10

AIM: Student database
You are tasked with creating a simple student database application using JDBC in Java. The application should allow users to perform the following operations on a students table in a database: 
1. Add a Student Record:
    ○ Insert a new student record into the students table. 
    ○ Each student record should have an ID (primary key), name, age, and major. 
2. Update a Student Record:
    ○ Update the details (name, age, major) of an existing student based on their ID.
3. Delete a Student Record:
    ○ Delete a student record from the students table based on their ID.
4. Search for a Student Record:
    ○ Search for a student record by their ID and display the details if found. 
5. Display All Student Records:
    ○ Retrieve and display all student records from the students table. 

ALGORITHM:
Load MySQL JDBC driver(class.forName("com.mysql.jdbc.Driver"))
Establish a connection to the MySQL database using DriverManager.getConnection()
Create a statement stmt using con.createStatement()
Use stmt to execute the query "select * from admission" and store the result in ResultSet rs
While rs has more data
{
    Print each data set
}
Close the connection
*/
//CODE:
import java.sql.*;

public class MysqlCon {
    public static void main(String args[]) {
        try {
            Class.forName("com.mysql.jdbc.Driver");
            Connection con = DriverManager.getConnection("jdbc:mysql://172.30.1.6:3306/student", "student", "q1w2e3r4");
            // here student is the database name, student is the username and q1w2e3r4 is
            // the password
            // mysql server is 172.30.1.6 running on port 3306
            Statement stmt = con.createStatement();
            ResultSet rs = stmt.executeQuery("select * from admission");
            while (rs.next())
                System.out.println(rs.getInt(1) + "" + rs.getString(2));
            con.close();
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}