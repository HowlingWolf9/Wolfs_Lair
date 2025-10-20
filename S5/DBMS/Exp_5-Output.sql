mysql> CREATE VIEW student_info AS
    -> SELECT studentNo, studentName, department, address
    -> FROM student;
Query OK, 0 rows affected (0.10 sec)

mysql> SELECT * FROM student_info;
+-----------+-------------+------------+-----------+
| studentNo | studentName | department | address   |
+-----------+-------------+------------+-----------+
|       100 | Hari        | CSE        | Kasaragod |
|       100 | Sam         | CSE        | Thrissur  |
|       101 | Devi        | CSE        | Kasaragod |
|       102 | Sam         | IT         | Kannur    |
|       103 | Sreehari    | IT         | Calicut   |
|       104 | Rani        | ECE        | Kannur    |
|       105 | Raj         | CSE        | Palakkad  |
+-----------+-------------+------------+-----------+
7 rows in set (0.01 sec)

mysql> CREATE VIEW student_mark AS
    -> SELECT studentNo, studentName, maths, physics, chemistry, cProgramming
    -> FROM student;
Query OK, 0 rows affected (0.15 sec)

mysql> SELECT * FROM student_mark;
+-----------+-------------+-------+---------+-----------+--------------+
| studentNo | studentName | maths | physics | chemistry | cProgramming |
+-----------+-------------+-------+---------+-----------+--------------+
|       100 | Hari        |    50 |      60 |        45 |           75 |
|       100 | Sam         |   100 |     100 |       100 |            0 |
|       101 | Devi        |    60 |      55 |        78 |           40 |
|       102 | Sam         |    45 |      77 |        88 |           45 |
|       103 | Sreehari    |    90 |      75 |        77 |           60 |
|       104 | Rani        |    91 |      98 |        89 |           52 |
|       105 | Raj         |    88 |      77 |        67 |           48 |
+-----------+-------------+-------+---------+-----------+--------------+
7 rows in set (0.00 sec)

mysql> SELECT 
    ->     sm.studentNo,
    ->     sm.studentName,
    ->     (sm.maths + sm.physics + sm.chemistry + sm.cProgramming) AS totalMarks,
    ->     si.address
    -> FROM student_mark sm
    -> JOIN student_info si ON sm.studentNo = si.studentNo;
+-----------+-------------+------------+-----------+
| studentNo | studentName | totalMarks | address   |
+-----------+-------------+------------+-----------+
|       100 | Hari        |        230 | Kasaragod |
|       100 | Hari        |        230 | Thrissur  |
|       100 | Sam         |        300 | Kasaragod |
|       100 | Sam         |        300 | Thrissur  |
|       101 | Devi        |        233 | Kasaragod |
|       102 | Sam         |        255 | Kannur    |
|       103 | Sreehari    |        302 | Calicut   |
|       104 | Rani        |        330 | Kannur    |
|       105 | Raj         |        280 | Palakkad  |
+-----------+-------------+------------+-----------+
9 rows in set (0.00 sec)

mysql> CREATE VIEW emp_dept AS
    -> SELECT e.empName, d.deptName
    -> FROM emp e
    -> LEFT JOIN dept d ON e.deptNo = d.deptNo;
Query OK, 0 rows affected (0.12 sec)

mysql> SELECT * FROM emp_dept;
+---------+-----------+
| empName | deptName  |
+---------+-----------+
| Hari    | NULL      |
| Devi    | Marketing |
| Gupta   | Sales     |
| Ravi    | Testing   |
| Rani    | NULL      |
| John    | Sales     |
+---------+-----------+
6 rows in set (0.01 sec)

mysql> SELECT empName
    -> FROM emp_dept
    -> WHERE deptName IS NULL;
+---------+
| empName |
+---------+
| Hari    |
| Rani    |
+---------+
2 rows in set (0.00 sec)