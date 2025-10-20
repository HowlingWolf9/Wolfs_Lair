mysql> CREATE TABLE student (
    ->     studentNo INT PRIMARY KEY,
    ->     studentName VARCHAR(50),
    ->     maths INT, 
    ->     physics INT, 
    ->     chemistry INT, 
    ->     cProgramming INT, 
    ->     department VARCHAR(10),
    ->     address VARCHAR(50)
    -> );

mysql> DESC student;
+--------------+-------------+------+-----+---------+-------+
| Field        | Type        | Null | Key | Default | Extra |
+--------------+-------------+------+-----+---------+-------+
| studentNo    | int         | NO   | PRI | NULL    |       |
| studentName  | varchar(50) | YES  |     | NULL    |       |
| maths        | int         | YES  |     | NULL    |       |
| physics      | int         | YES  |     | NULL    |       |
| chemistry    | int         | YES  |     | NULL    |       |
| cProgramming | int         | YES  |     | NULL    |       |
| department   | varchar(10) | YES  |     | NULL    |       |
| address      | varchar(50) | YES  |     | NULL    |       |
+--------------+-------------+------+-----+---------+-------+
8 rows in set (0.00 sec)

mysql> INSERT INTO student
    -> VALUES 
    ->     (100, 'Hari', 50, 60, 45, 75, 'CSE', 'Kasaragod'),
    ->     (101, 'Devi', 60, 55, 78, 40, 'CSE', 'Kasaragod'),
    ->     (102, 'Sam', 45, 77, 88, 45, 'IT', 'Kannur'),
    ->     (103, 'Sreehari', 90, 75, 77, 60, 'IT', 'Calicut'),
    ->     (104, 'Rani', 91, 98, 89, 52, 'ECE', 'Kannur'),
    ->     (105, 'Raj', 88, 77, 67, 48, 'CSE', 'Palakkad');
Records: 6  Duplicates: 0  Warnings: 0

mysql> SELECT *
    -> FROM student;
+-----------+-------------+-------+---------+-----------+--------------+------------+-----------+
| studentNo | studentName | maths | physics | chemistry | cProgramming | department | address   |
+-----------+-------------+-------+---------+-----------+--------------+------------+-----------+
|       100 | Hari        |    50 |      60 |        45 |           75 | CSE        | Kasaragod |
|       101 | Devi        |    60 |      55 |        78 |           40 | CSE        | Kasaragod |
|       102 | Sam         |    45 |      77 |        88 |           45 | IT         | Kannur    |
|       103 | Sreehari    |    90 |      75 |        77 |           60 | IT         | Calicut   |
|       104 | Rani        |    91 |      98 |        89 |           52 | ECE        | Kannur    |
|       105 | Raj         |    88 |      77 |        67 |           48 | CSE        | Palakkad  |
+-----------+-------------+-------+---------+-----------+--------------+------------+-----------+
6 rows in set (0.00 sec)

mysql> SELECT 
    ->     studentNo,
    ->     studentName
    -> FROM student
    -> WHERE cProgramming < 50
    -> ORDER BY cProgramming ASC;
+-----------+-------------+
| studentNo | studentName |
+-----------+-------------+
|       101 | Devi        |
|       102 | Sam         |
|       105 | Raj         |
+-----------+-------------+
3 rows in set (0.00 sec)

mysql> SELECT 
    ->     studentNo,
    ->     studentName,
    ->     department
    -> FROM student
    -> ORDER BY 
    ->     department DESC,
    ->     studentName ASC;
+-----------+-------------+------------+
| studentNo | studentName | department |
+-----------+-------------+------------+
|       102 | Sam         | IT         |
|       103 | Sreehari    | IT         |
|       104 | Rani        | ECE        |
|       101 | Devi        | CSE        |
|       100 | Hari        | CSE        |
|       105 | Raj         | CSE        |
+-----------+-------------+------------+
6 rows in set (0.00 sec)

mysql> SELECT studentName
    -> FROM student
    -> WHERE studentName LIKE 'S%';
+-------------+
| studentName |
+-------------+
| Sam         |
| Sreehari    |
+-------------+
2 rows in set (0.00 sec)

mysql> SELECT studentName
    -> FROM student
    -> ORDER BY cProgramming DESC
    -> LIMIT 1
    -> OFFSET 1;
+-------------+
| studentName |
+-------------+
| Sreehari    |
+-------------+
1 row in set (0.00 sec)

mysql> SELECT 
    ->     department,
    ->     COUNT(department) AS student_count,
    ->     AVG(maths) AS avg_maths_score
    -> FROM student
    -> GROUP BY department;
+------------+---------------+-----------------+
| department | student_count | avg_maths_score |
+------------+---------------+-----------------+
| CSE        |             3 |         66.0000 |
| IT         |             2 |         67.5000 |
| ECE        |             1 |         91.0000 |
+------------+---------------+-----------------+
3 rows in set (0.00 sec)

mysql> SELECT COUNT(studentNo) AS student_count
    -> FROM student
    -> WHERE physics BETWEEN 70 AND 80;
+---------------+
| student_count |
+---------------+
|             3 |
+---------------+
1 row in set (0.00 sec)

mysql> ALTER TABLE student 
    -> DROP PRIMARY KEY;
Records: 6  Duplicates: 0  Warnings: 0

mysql> DESC student;
+--------------+-------------+------+-----+---------+-------+
| Field        | Type        | Null | Key | Default | Extra |
+--------------+-------------+------+-----+---------+-------+
| studentNo    | int         | NO   |     | NULL    |       |
| studentName  | varchar(50) | YES  |     | NULL    |       |
| maths        | int         | YES  |     | NULL    |       |
| physics      | int         | YES  |     | NULL    |       |
| chemistry    | int         | YES  |     | NULL    |       |
| cProgramming | int         | YES  |     | NULL    |       |
| department   | varchar(10) | YES  |     | NULL    |       |
| address      | varchar(50) | YES  |     | NULL    |       |
+--------------+-------------+------+-----+---------+-------+
8 rows in set (0.00 sec)

mysql> ALTER TABLE student 
    -> ADD PRIMARY KEY (studentNo, studentName);
Query OK, 0 rows affected (0.03 sec)
Records: 0  Duplicates: 0  Warnings: 0

mysql> DESC student;
+--------------+-------------+------+-----+---------+-------+
| Field        | Type        | Null | Key | Default | Extra |
+--------------+-------------+------+-----+---------+-------+
| studentNo    | int         | NO   | PRI | NULL    |       |
| studentName  | varchar(50) | NO   | PRI | NULL    |       |
| maths        | int         | YES  |     | NULL    |       |
| physics      | int         | YES  |     | NULL    |       |
| chemistry    | int         | YES  |     | NULL    |       |
| cProgramming | int         | YES  |     | NULL    |       |
| department   | varchar(10) | YES  |     | NULL    |       |
| address      | varchar(50) | YES  |     | NULL    |       |
+--------------+-------------+------+-----+---------+-------+
8 rows in set (0.00 sec)

mysql> INSERT INTO student
    -> VALUES (100, 'Sam', 100, 100, 100, 0, 'CSE', 'Thrissur');
Query OK, 1 row affected (0.00 sec)

mysql> SELECT *
    -> FROM student;
+-----------+-------------+-------+---------+-----------+--------------+------------+-----------+
| studentNo | studentName | maths | physics | chemistry | cProgramming | department | address   |
+-----------+-------------+-------+---------+-----------+--------------+------------+-----------+
|       100 | Hari        |    50 |      60 |        45 |           75 | CSE        | Kasaragod |
|       100 | Sam         |   100 |     100 |       100 |            0 | CSE        | Thrissur  |
|       101 | Devi        |    60 |      55 |        78 |           40 | CSE        | Kasaragod |
|       102 | Sam         |    45 |      77 |        88 |           45 | IT         | Kannur    |
|       103 | Sreehari    |    90 |      75 |        77 |           60 | IT         | Calicut   |
|       104 | Rani        |    91 |      98 |        89 |           52 | ECE        | Kannur    |
|       105 | Raj         |    88 |      77 |        67 |           48 | CSE        | Palakkad  |
+-----------+-------------+-------+---------+-----------+--------------+------------+-----------+
7 rows in set (0.00 sec)