mysql> CREATE TABLE file_server (
    ->     user_id INT,
    ->     file_name VARCHAR(100),
    ->     create_date DATE
    -> );
Query OK, 0 rows affected (0.02 sec)

mysql> DESC file_server;
+-------------+--------------+------+-----+---------+-------+
| Field       | Type         | Null | Key | Default | Extra |
+-------------+--------------+------+-----+---------+-------+
| user_id     | int          | YES  |     | NULL    |       |
| file_name   | varchar(100) | YES  |     | NULL    |       |
| create_date | date         | YES  |     | NULL    |       |
+-------------+--------------+------+-----+---------+-------+
3 rows in set (0.01 sec)

mysql> INSERT INTO file_server 
    -> VALUES 
    ->     (1, 'debug.txt' , '2024-06-01'),
    ->     (1,'exp.txt','2024-07-01'),
    ->     (1,'string.java','2024-07-10'),
    ->     (2,'add.c','2024-08-01'), 
    ->     (2,'sub.asm','2024-08-09'),
    ->     (2,'sub2.Asm','2024-08-14'),
    ->     (3,'even.c','2024-08-18'),
    ->     (3,'fibonacci.c','2024-08-12'),
    ->     (3,'Hello.txt','2024-08-27'),
    ->     (3,'traffic.java','2024-08-09'),
    ->     (4,'EMP.TXT','2024-08-21'),
    ->     (4,'employee.txt','2024-08-19');
Query OK, 12 rows affected (0.01 sec)
Records: 12  Duplicates: 0  Warnings: 0

mysql> SELECT *
    -> FROM file_server;
+---------+--------------+-------------+
| user_id | file_name    | create_date |
+---------+--------------+-------------+
|       1 | debug.txt    | 2024-06-01  |
|       1 | exp.txt      | 2024-07-01  |
|       1 | string.java  | 2024-07-10  |
|       2 | add.c        | 2024-08-01  |
|       2 | sub.asm      | 2024-08-09  |
|       2 | sub2.Asm     | 2024-08-14  |
|       3 | even.c       | 2024-08-18  |
|       3 | fibonacci.c  | 2024-08-12  |
|       3 | Hello.txt    | 2024-08-27  |
|       3 | traffic.java | 2024-08-09  |
|       4 | EMP.TXT      | 2024-08-21  |
|       4 | employee.txt | 2024-08-19  |
+---------+--------------+-------------+
12 rows in set (0.00 sec)

mysql> SELECT DISTINCT SUBSTRING_INDEX(file_name,'.',-1) 
    -> AS 'Unique extensions'
    -> FROM file_server;
+-------------------+
| Unique extensions |
+-------------------+
| txt               |
| java              |
| c                 |
| asm               |
+-------------------+
4 rows in set (0.01 sec)

mysql> SELECT 
    ->     user_id,
    ->     SUBSTRING_INDEX(file_name,'.',-1) AS 'Extension',
    ->     COUNT(*) AS 'File Count'
    -> FROM file_server
    -> GROUP BY 
    ->     user_id,
    ->     Extension;
+---------+-----------+------------+
| user_id | Extension | File Count |
+---------+-----------+------------+
|       1 | txt       |          2 |
|       1 | java      |          1 |
|       2 | c         |          1 |
|       2 | asm       |          2 |
|       3 | c         |          2 |
|       3 | txt       |          1 |
|       3 | java      |          1 |
|       4 | TXT       |          2 |
+---------+-----------+------------+
8 rows in set (0.00 sec)

mysql> SELECT * 
    -> FROM file_server
    -> WHERE create_date
    -> BETWEEN DATE_ADD('2024-08-15', INTERVAL -7 DAY)
    -> AND DATE_ADD('2024-08-15', INTERVAL 7 DAY);
+---------+--------------+-------------+
| user_id | file_name    | create_date |
+---------+--------------+-------------+
|       2 | sub.asm      | 2024-08-09  |
|       2 | sub2.Asm     | 2024-08-14  |
|       3 | even.c       | 2024-08-18  |
|       3 | fibonacci.c  | 2024-08-12  |
|       3 | traffic.java | 2024-08-09  |
|       4 | EMP.TXT      | 2024-08-21  |
|       4 | employee.txt | 2024-08-19  |
+---------+--------------+-------------+
7 rows in set (0.00 sec)