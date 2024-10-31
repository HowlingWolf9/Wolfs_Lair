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