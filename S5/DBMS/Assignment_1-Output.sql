mysql> CREATE TABLE EMP(
    -> EMPNO INT PRIMARY KEY, 
    -> ENAME VARCHAR(25), 
    -> JOB VARCHAR(25),
    -> MGR INT,
    -> HIREDATE DATE,  
    -> SAL INT, 
    -> COMM INT, 
    -> DEPTNO INT
    -> );
Query OK, 0 rows affected (1.16 sec)

mysql> DESC EMP;
+----------+-------------+------+-----+---------+-------+
| Field    | Type        | Null | Key | Default | Extra |
+----------+-------------+------+-----+---------+-------+
| EMPNO    | int         | NO   | PRI | NULL    |       |
| ENAME    | varchar(25) | YES  |     | NULL    |       |
| JOB      | varchar(25) | YES  |     | NULL    |       |
| MGR      | int         | YES  |     | NULL    |       |
| HIREDATE | date        | YES  |     | NULL    |       |
| SAL      | int         | YES  |     | NULL    |       |
| COMM     | int         | YES  |     | NULL    |       |
| DEPTNO   | int         | YES  |     | NULL    |       |
+----------+-------------+------+-----+---------+-------+
8 rows in set (0.00 sec)

mysql> INSERT INTO EMP VALUES
    -> (7369, 'SMITH', 'CLERK', 7902, '1980-12-17', 800, NULL, 20),
    -> (7499, 'ALLEN', 'SALESMAN', 7698, '1981-03-20', 1600, 300, 30),
    -> (7521, 'WARD', 'SALESMAN', 7698, '1981-03-22', 1250, 500, 30),
    -> (7566, 'JONES', 'MANAGER', 7839, '1981-04-02', 2975, NULL, 20),
    -> (7654, 'MARTIN', 'SALESMAN', 7698, '1981-09-28', 1250, 1400, 30),
    -> (7698, 'BLAKE', 'MANAGER', 7839, '1981-05-01', 2850, NULL, 30),
    -> (7782, 'CLARK', 'MANAGER', 7839, '1981-06-19', 2450, NULL, 10),
    -> (7788, 'SCOTT', 'ANALYST', 7566, '1987-04-19', 3000, NULL, 20),
    -> (7839, 'KING', 'PRESIDENT', NULL, '1981-11-17', 5000, NULL, 10),
    -> (7844, 'TURNER', 'SALESMAN', 7698, '1981-09-08', 1500, 0, 30),
    -> (7876, 'ADAMS', 'CLERK', 7788, '1987-05-23', 1100, NULL, 20),
    -> (7900, 'JAMES', 'CLERK', 7698, '1981-12-03', 950, NULL, 30),
    -> (7902, 'FORD', 'ANALYST', 7566, '1981-12-03', 3000, NULL, 20),
    -> (7934, 'MILLER', 'CLERK', 7782, '1982-01-23', 1300, NULL, 10);
Query OK, 14 rows affected (0.10 sec)
Records: 14  Duplicates: 0  Warnings: 0

mysql> SELECT * FROM EMP;
+-------+--------+-----------+------+------------+------+------+--------+
| EMPNO | ENAME  | JOB       | MGR  | HIREDATE   | SAL  | COMM | DEPTNO |
+-------+--------+-----------+------+------------+------+------+--------+
|  7369 | SMITH  | CLERK     | 7902 | 1980-12-17 |  800 | NULL |     20 |
|  7499 | ALLEN  | SALESMAN  | 7698 | 1981-03-20 | 1600 |  300 |     30 |
|  7521 | WARD   | SALESMAN  | 7698 | 1981-03-22 | 1250 |  500 |     30 |
|  7566 | JONES  | MANAGER   | 7839 | 1981-04-02 | 2975 | NULL |     20 |
|  7654 | MARTIN | SALESMAN  | 7698 | 1981-09-28 | 1250 | 1400 |     30 |
|  7698 | BLAKE  | MANAGER   | 7839 | 1981-05-01 | 2850 | NULL |     30 |
|  7782 | CLARK  | MANAGER   | 7839 | 1981-06-19 | 2450 | NULL |     10 |
|  7788 | SCOTT  | ANALYST   | 7566 | 1987-04-19 | 3000 | NULL |     20 |
|  7839 | KING   | PRESIDENT | NULL | 1981-11-17 | 5000 | NULL |     10 |
|  7844 | TURNER | SALESMAN  | 7698 | 1981-09-08 | 1500 |    0 |     30 |
|  7876 | ADAMS  | CLERK     | 7788 | 1987-05-23 | 1100 | NULL |     20 |
|  7900 | JAMES  | CLERK     | 7698 | 1981-12-03 |  950 | NULL |     30 |
|  7902 | FORD   | ANALYST   | 7566 | 1981-12-03 | 3000 | NULL |     20 |
|  7934 | MILLER | CLERK     | 7782 | 1982-01-23 | 1300 | NULL |     10 |
+-------+--------+-----------+------+------------+------+------+--------+
14 rows in set (0.00 sec)

mysql> CREATE TABLE DEPT(
    -> DEPTNO INT PRIMARY KEY,
    -> DNAME VARCHAR(25),
    -> LOC VARCHAR(50)
    -> );
Query OK, 0 rows affected (0.50 sec)

mysql> DESC DEPT;
+--------+-------------+------+-----+---------+-------+
| Field  | Type        | Null | Key | Default | Extra |
+--------+-------------+------+-----+---------+-------+
| DEPTNO | int         | NO   | PRI | NULL    |       |
| DNAME  | varchar(25) | YES  |     | NULL    |       |
| LOC    | varchar(50) | YES  |     | NULL    |       |
+--------+-------------+------+-----+---------+-------+
3 rows in set (0.00 sec)

mysql> 
mysql> INSERT INTO DEPT VALUES
    -> (10, 'ACCOUNTING', 'NEW YORK'),
    -> (20, 'RESEARCH', 'DALLAS'),
    -> (30, 'SALES', 'CHICAGO'),
    -> (40, 'OPERATIONS', 'BOSTON');
Query OK, 4 rows affected (0.07 sec)
Records: 4  Duplicates: 0  Warnings: 0

mysql> SELECT * FROM DEPT;
+--------+------------+----------+
| DEPTNO | DNAME      | LOC      |
+--------+------------+----------+
|     10 | ACCOUNTING | NEW YORK |
|     20 | RESEARCH   | DALLAS   |
|     30 | SALES      | CHICAGO  |
|     40 | OPERATIONS | BOSTON   |
+--------+------------+----------+
4 rows in set (0.00 sec)

mysql> SELECT * FROM EMP;
+-------+--------+-----------+------+------------+------+------+--------+
| EMPNO | ENAME  | JOB       | MGR  | HIREDATE   | SAL  | COMM | DEPTNO |
+-------+--------+-----------+------+------------+------+------+--------+
|  7369 | SMITH  | CLERK     | 7902 | 1980-12-17 |  800 | NULL |     20 |
|  7499 | ALLEN  | SALESMAN  | 7698 | 1981-03-20 | 1600 |  300 |     30 |
|  7521 | WARD   | SALESMAN  | 7698 | 1981-03-22 | 1250 |  500 |     30 |
|  7566 | JONES  | MANAGER   | 7839 | 1981-04-02 | 2975 | NULL |     20 |
|  7654 | MARTIN | SALESMAN  | 7698 | 1981-09-28 | 1250 | 1400 |     30 |
|  7698 | BLAKE  | MANAGER   | 7839 | 1981-05-01 | 2850 | NULL |     30 |
|  7782 | CLARK  | MANAGER   | 7839 | 1981-06-19 | 2450 | NULL |     10 |
|  7788 | SCOTT  | ANALYST   | 7566 | 1987-04-19 | 3000 | NULL |     20 |
|  7839 | KING   | PRESIDENT | NULL | 1981-11-17 | 5000 | NULL |     10 |
|  7844 | TURNER | SALESMAN  | 7698 | 1981-09-08 | 1500 |    0 |     30 |
|  7876 | ADAMS  | CLERK     | 7788 | 1987-05-23 | 1100 | NULL |     20 |
|  7900 | JAMES  | CLERK     | 7698 | 1981-12-03 |  950 | NULL |     30 |
|  7902 | FORD   | ANALYST   | 7566 | 1981-12-03 | 3000 | NULL |     20 |
|  7934 | MILLER | CLERK     | 7782 | 1982-01-23 | 1300 | NULL |     10 |
+-------+--------+-----------+------+------------+------+------+--------+
14 rows in set (0.00 sec)

mysql> SELECT * 
    -> FROM EMP 
    -> WHERE DEPTNO = 20;
+-------+-------+---------+------+------------+------+------+--------+
| EMPNO | ENAME | JOB     | MGR  | HIREDATE   | SAL  | COMM | DEPTNO |
+-------+-------+---------+------+------------+------+------+--------+
|  7369 | SMITH | CLERK   | 7902 | 1980-12-17 |  800 | NULL |     20 |
|  7566 | JONES | MANAGER | 7839 | 1981-04-02 | 2975 | NULL |     20 |
|  7788 | SCOTT | ANALYST | 7566 | 1987-04-19 | 3000 | NULL |     20 |
|  7876 | ADAMS | CLERK   | 7788 | 1987-05-23 | 1100 | NULL |     20 |
|  7902 | FORD  | ANALYST | 7566 | 1981-12-03 | 3000 | NULL |     20 |
+-------+-------+---------+------+------------+------+------+--------+
5 rows in set (0.00 sec)


mysql> SELECT EMPNO,ENAME 
    -> FROM EMP 
    -> WHERE JOB = 'MANAGER';
+-------+-------+
| EMPNO | ENAME |
+-------+-------+
|  7566 | JONES |
|  7698 | BLAKE |
|  7782 | CLARK |
+-------+-------+
3 rows in set (0.00 sec)

mysql> SELECT ENAME 
    -> FROM EMP 
    -> WHERE JOB = 'CLERK' 
    -> AND DEPTNO = 20;
+-------+
| ENAME |
+-------+
| SMITH |
| ADAMS |
+-------+
2 rows in set (0.00 sec)

mysql> SELECT ENAME 
    -> FROM EMP 
    -> WHERE JOB = 'ANALYST' 
    -> OR JOB = 'SALESMAN';
+--------+
| ENAME  |
+--------+
| ALLEN  |
| WARD   |
| MARTIN |
| SCOTT  |
| TURNER |
| FORD   |
+--------+

mysql> SELECT ENAME 
    -> FROM EMP 
    -> WHERE HIREDATE < '1981-09-30';
+--------+
| ENAME  |
+--------+
| SMITH  |
| ALLEN  |
| WARD   |
| JONES  |
| MARTIN |
| BLAKE  |
| CLARK  |
| TURNER |
+--------+
8 rows in set (0.00 sec)

mysql> SELECT ENAME 
    -> FROM EMP 
    -> WHERE JOB != 'MANAGER';
+--------+
| ENAME  |
+--------+
| SMITH  |
| ALLEN  |
| WARD   |
| MARTIN |
| SCOTT  |
| KING   |
| TURNER |
| ADAMS  |
| JAMES  |
| FORD   |
| MILLER |
+--------+
11 rows in set (0.00 sec)

