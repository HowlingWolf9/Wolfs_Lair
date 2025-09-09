mysql> CREATE TABLE employee   (empNo INT PRIMARY KEY,
    ->                         empName VARCHAR(25),
    ->                         empAddress VARCHAR(50),
    ->                         salary INT, dept VARCHAR(20));
Query OK, 0 rows affected (0.03 sec)

mysql> DESC employee;
+------------+-------------+------+-----+---------+-------+
| Field      | Type        | Null | Key | Default | Extra |
+------------+-------------+------+-----+---------+-------+
| empNo      | int         | NO   | PRI | NULL    |       |
| empName    | varchar(25) | YES  |     | NULL    |       |
| empAddress | varchar(50) | YES  |     | NULL    |       |
| salary     | int         | YES  |     | NULL    |       |
| dept       | varchar(20) | YES  |     | NULL    |       |
+------------+-------------+------+-----+---------+-------+
5 rows in set (0.01 sec)

mysql> INSERT INTO employee
    -> VALUES (2001, 'Hari', 'Palakkad', 30000, 'Reasearch'),
    ->        (2002, 'Devi', 'Kasaragod', 40000, 'Network'),
    ->        (2003, 'Gupta', 'Kannur', 50000, 'System Admin'),
    ->        (2004, 'Ravi', 'Calicut', 60000, 'HR'),
    ->        (2005, 'Rani', 'Calicut', 70000, 'HR');
Query OK, 5 rows affected (0.01 sec)
Records: 5  Duplicates: 0  Warnings: 0

mysql> SELECT *
    -> FROM employee;
+-------+---------+------------+--------+--------------+
| empNo | empName | empAddress | salary | dept         |
+-------+---------+------------+--------+--------------+
|  2001 | Hari    | Palakkad   |  30000 | Reasearch    |
|  2002 | Devi    | Kasaragod  |  40000 | Network      |
|  2003 | Gupta   | Kannur     |  50000 | System Admin |
|  2004 | Ravi    | Calicut    |  60000 | HR           |
|  2005 | Rani    | Calicut    |  70000 | HR           |
+-------+---------+------------+--------+--------------+
5 rows in set (0.01 sec)

mysql> SELECT SUM(salary)
    -> FROM employee;
+-------------+
| SUM(salary) |
+-------------+
|      250000 |
+-------------+
1 row in set (0.00 sec)

mysql> SELECT COUNT(salary)
    -> FROM employee
    -> WHERE salary < 50000;
+---------------+
| COUNT(salary) |
+---------------+
|             2 |
+---------------+
1 row in set (0.00 sec)

mysql> SELECT *
    -> FROM employee
    -> WHERE salary =
    ->     (SELECT MAX(salary)
    ->      FROM employee);
+-------+---------+------------+--------+------+
| empNo | empName | empAddress | salary | dept |
+-------+---------+------------+--------+------+
|  2005 | Rani    | Calicut    |  70000 | HR   |
+-------+---------+------------+--------+------+
1 row in set (0.00 sec)

mysql> ALTER TABLE employee
    -> ADD column (title VARCHAR(25) DEFAULT ('junior software engineer'));
Query OK, 5 rows affected (0.05 sec)
Records: 5  Duplicates: 0  Warnings: 0

mysql> SELECT *
    -> FROM employee;
+-------+---------+------------+--------+--------------+--------------------------+
| empNo | empName | empAddress | salary | dept         | title                    |
+-------+---------+------------+--------+--------------+--------------------------+
|  2001 | Hari    | Palakkad   |  30000 | Reasearch    | junior software engineer |
|  2002 | Devi    | Kasaragod  |  40000 | Network      | junior software engineer |
|  2003 | Gupta   | Kannur     |  50000 | System Admin | junior software engineer |
|  2004 | Ravi    | Calicut    |  60000 | HR           | junior software engineer |
|  2005 | Rani    | Calicut    |  70000 | HR           | junior software engineer |
+-------+---------+------------+--------+--------------+--------------------------+
5 rows in set (0.00 sec)

mysql> UPDATE employee
    -> SET title = 'senior software engineer'
    -> WHERE empNo = 2004;
Query OK, 1 row affected (0.00 sec)
Rows matched: 1  Changed: 1  Warnings: 0

mysql> SELECT *
    -> FROM employee;
+-------+---------+------------+--------+--------------+--------------------------+
| empNo | empName | empAddress | salary | dept         | title                    |
+-------+---------+------------+--------+--------------+--------------------------+
|  2001 | Hari    | Palakkad   |  30000 | Reasearch    | junior software engineer |
|  2002 | Devi    | Kasaragod  |  40000 | Network      | junior software engineer |
|  2003 | Gupta   | Kannur     |  50000 | System Admin | junior software engineer |
|  2004 | Ravi    | Calicut    |  60000 | HR           | senior software engineer |
|  2005 | Rani    | Calicut    |  70000 | HR           | junior software engineer |
+-------+---------+------------+--------+--------------+--------------------------+
5 rows in set (0.00 sec)

mysql> DELETE
    -> FROM employee
    -> WHERE empNo = 2005;
Query OK, 1 row affected (0.01 sec)

mysql> SELECT *
    -> FROM employee;
+-------+---------+------------+--------+--------------+--------------------------+
| empNo | empName | empAddress | salary | dept         | title                    |
+-------+---------+------------+--------+--------------+--------------------------+
|  2001 | Hari    | Palakkad   |  30000 | Reasearch    | junior software engineer |
|  2002 | Devi    | Kasaragod  |  40000 | Network      | junior software engineer |
|  2003 | Gupta   | Kannur     |  50000 | System Admin | junior software engineer |
|  2004 | Ravi    | Calicut    |  60000 | HR           | senior software engineer |
+-------+---------+------------+--------+--------------+--------------------------+
4 rows in set (0.00 sec)