mysql> CREATE TABLE emp (
    ->     empId INT PRIMARY KEY,
    ->     empName VARCHAR(100),
    ->     deptNo INT,
    ->     salary INT
    -> );
Query OK, 0 rows affected (0.02 sec)

mysql> DESC emp;
+---------+--------------+------+-----+---------+-------+
| Field   | Type         | Null | Key | Default | Extra |
+---------+--------------+------+-----+---------+-------+
| empId   | int          | NO   | PRI | NULL    |       |
| empName | varchar(100) | YES  |     | NULL    |       |
| deptNo  | int          | YES  |     | NULL    |       |
| salary  | int          | YES  |     | NULL    |       |
+---------+--------------+------+-----+---------+-------+
4 rows in set (0.00 sec)

mysql> INSERT INTO emp
    -> VALUES
    ->     (2001, 'Hari', 1006, 30000),
    ->     (2002, 'Devi', 1002, 40000),
    ->     (2003, 'Gupta', 1003, 50000),
    ->     (2004, 'Ravi', 1004, 60000),
    ->     (2005, 'Rani', 1007, 70000),
    ->     (2006, 'John', 1003, 40000);
Query OK, 6 rows affected (0.00 sec)
Records: 6  Duplicates: 0  Warnings: 0

mysql> SELECT *
    -> FROM emp;
+-------+---------+--------+--------+
| empId | empName | deptNo | salary |
+-------+---------+--------+--------+
|  2001 | Hari    |   1006 |  30000 |
|  2002 | Devi    |   1002 |  40000 |
|  2003 | Gupta   |   1003 |  50000 |
|  2004 | Ravi    |   1004 |  60000 |
|  2005 | Rani    |   1007 |  70000 |
|  2006 | John    |   1003 |  40000 |
+-------+---------+--------+--------+
6 rows in set (0.00 sec)

mysql> CREATE TABLE dept (
    ->     deptNo INT PRIMARY KEY,
    ->     deptName VARCHAR(100),
    ->     deptLocation VARCHAR(100)
    -> );
Query OK, 0 rows affected (0.02 sec)

mysql> DESC dept;
+--------------+--------------+------+-----+---------+-------+
| Field        | Type         | Null | Key | Default | Extra |
+--------------+--------------+------+-----+---------+-------+
| deptNo       | int          | NO   | PRI | NULL    |       |
| deptName     | varchar(100) | YES  |     | NULL    |       |
| deptLocation | varchar(100) | YES  |     | NULL    |       |
+--------------+--------------+------+-----+---------+-------+
3 rows in set (0.00 sec)

mysql> INSERT INTO dept
    -> VALUES
    ->     (1001, 'HR', 'Calicut'),
    ->     (1002, 'Marketing', 'Cochin'),
    ->     (1003, 'Sales', 'Trivandrum'),
    ->     (1004, 'Testing', 'Bangalore'),
    ->     (1005, 'Development', 'Bangalore');
Query OK, 5 rows affected (0.01 sec)
Records: 5  Duplicates: 0  Warnings: 0

mysql> SELECT *
    -> FROM dept;
+--------+-------------+--------------+
| deptNo | deptName    | deptLocation |
+--------+-------------+--------------+
|   1001 | HR          | Calicut      |
|   1002 | Marketing   | Cochin       |
|   1003 | Sales       | Trivandrum   |
|   1004 | Testing     | Bangalore    |
|   1005 | Development | Bangalore    |
+--------+-------------+--------------+
5 rows in set (0.00 sec)

mysql> SELECT 
    ->     empName,
    ->     deptName
    -> FROM 
    ->     emp e,
    ->     dept d
    -> WHERE e.deptNo = d.deptNo;
+---------+-----------+
| empName | deptName  |
+---------+-----------+
| Devi    | Marketing |
| Gupta   | Sales     |
| Ravi    | Testing   |
| John    | Sales     |
+---------+-----------+
4 rows in set (0.00 sec)

mysql> SELECT
    ->     empId,
    ->     empName,
    ->     deptNo
    -> FROM emp
    -> WHERE deptNo 
    -> NOT IN (
    ->     SELECT deptNo
    ->     FROM dept
    -> );
+-------+---------+--------+
| empId | empName | deptNo |
+-------+---------+--------+
|  2001 | Hari    |   1006 |
|  2005 | Rani    |   1007 |
+-------+---------+--------+
2 rows in set (0.00 sec)

mysql> SELECT deptNo
    -> FROM emp
    -> UNION
    -> SELECT deptNo
    -> FROM dept;
+--------+
| deptNo |
+--------+
|   1006 |
|   1002 |
|   1003 |
|   1004 |
|   1007 |
|   1001 |
|   1005 |
+--------+
7 rows in set (0.00 sec)

mysql> SELECT
    ->     deptNo,
    ->     deptName
    -> FROM dept
    -> WHERE deptNo 
    -> NOT IN (
    ->     SELECT deptNo
    ->     FROM emp
    -> );
+--------+-------------+
| deptNo | deptName    |
+--------+-------------+
|   1001 | HR          |
|   1005 | Development |
+--------+-------------+
2 rows in set (0.00 sec)

mysql> SELECT 
    ->     d.deptNo,
    ->     e.empId,
    ->     e.empName
    -> FROM
    ->     emp e,
    ->     dept d
    -> WHERE e.deptNo = d.deptNo
    -> AND d.deptLocation = 'Cochin';
+--------+-------+---------+
| deptNo | empId | empName |
+--------+-------+---------+
|   1002 |  2002 | Devi    |
+--------+-------+---------+
1 row in set (0.00 sec)

mysql> SELECT *
    -> FROM emp
    -> WHERE
    ->     salary > (
    ->         SELECT AVG(e.salary)
    ->         FROM 
    ->             emp e,
    ->             dept d
    ->         WHERE e.deptNo = d.deptNo
    ->         AND d.deptName = 'Sales'
    ->     );
+-------+---------+--------+--------+
| empId | empName | deptNo | salary |
+-------+---------+--------+--------+
|  2003 | Gupta   |   1003 |  50000 |
|  2004 | Ravi    |   1004 |  60000 |
|  2005 | Rani    |   1007 |  70000 |
+-------+---------+--------+--------+
3 rows in set (0.00 sec)

mysql> SELECT empName
    -> FROM emp
    -> WHERE salary > (
    ->     SELECT MAX(salary)
    ->     FROM emp
    ->     WHERE deptNo = 1003
    -> );
+---------+
| empName |
+---------+
| Ravi    |
| Rani    |
+---------+
2 rows in set (0.01 sec)

mysql> UPDATE emp 
    -> SET salary = 1.2 * salary
    -> WHERE deptno = (
    ->     SELECT deptno
    ->     FROM dept 
    ->     WHERE deptname = 'Sales'
    -> );
Query OK, 2 rows affected (0.01 sec)
Rows matched: 2  Changed: 2  Warnings: 0

mysql> SELECT
    ->     empid,
    ->     empName,
    ->     salary,
    ->     deptName
    -> FROM
    ->     emp e,
    ->     dept d
    -> WHERE e.deptno=d.deptno;
+-------+---------+--------+-----------+
| empid | empName | salary | deptName  |
+-------+---------+--------+-----------+
|  2002 | Devi    |  40000 | Marketing |
|  2003 | Gupta   |  60000 | Sales     |
|  2004 | Ravi    |  60000 | Testing   |
|  2006 | John    |  48000 | Sales     |
+-------+---------+--------+-----------+
4 rows in set (0.00 sec)

mysql> SELECT *
    -> FROM emp;
+-------+---------+--------+--------+
| empId | empName | deptNo | salary |
+-------+---------+--------+--------+
|  2001 | Hari    |   1006 |  30000 |
|  2002 | Devi    |   1002 |  40000 |
|  2003 | Gupta   |   1003 |  60000 |
|  2004 | Ravi    |   1004 |  60000 |
|  2005 | Rani    |   1007 |  70000 |
|  2006 | John    |   1003 |  48000 |
+-------+---------+--------+--------+
6 rows in set (0.00 sec)

mysql> SELECT e.empid
    -> FROM emp e 
    -> WHERE salary > (
    ->     SELECT AVG(salary)
    ->     FROM emp b 
    ->     WHERE b.deptno=e.deptno
    -> );
+-------+
| empid |
+-------+
|  2003 |
+-------+
1 row in set (0.00 sec)

mysql> SELECT 
    ->     deptno,
    ->     COUNT(*)
    -> FROM emp e
    -> WHERE salary > 40000 
    -> GROUP BY deptno 
    -> HAVING (
    ->     SELECT COUNT(*)
    ->     FROM emp f 
    ->     WHERE f.deptno = e.deptno
    ->     ) > 1;
+--------+----------+
| deptno | COUNT(*) |
+--------+----------+
|   1003 |        2 |
+--------+----------+
1 row in set (0.00 sec)