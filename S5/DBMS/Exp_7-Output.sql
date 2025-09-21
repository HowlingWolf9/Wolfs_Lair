mysql> CREATE TABLE customer (
    -> cust_id INT PRIMARY KEY,
    -> cust_name VARCHAR(50),
    -> cust_phone VARCHAR(5)
    -> );
Query OK, 0 rows affected (0.02 sec)

mysql> DESC customer;
+------------+-------------+------+-----+---------+-------+
| Field      | Type        | Null | Key | Default | Extra |
+------------+-------------+------+-----+---------+-------+
| cust_id    | int         | NO   | PRI | NULL    |       |
| cust_name  | varchar(50) | YES  |     | NULL    |       |
| cust_phone | varchar(5)  | YES  |     | NULL    |       |
+------------+-------------+------+-----+---------+-------+
3 rows in set (0.00 sec)

mysql> CREATE TABLE author (
    -> auth_name VARCHAR(50) PRIMARY KEY,
    -> country VARCHAR(50)
    -> );
Query OK, 0 rows affected (0.02 sec)

mysql> DESC author;
+-----------+-------------+------+-----+---------+-------+
| Field     | Type        | Null | Key | Default | Extra |
+-----------+-------------+------+-----+---------+-------+
| auth_name | varchar(50) | NO   | PRI | NULL    |       |
| country   | varchar(50) | YES  |     | NULL    |       |
+-----------+-------------+------+-----+---------+-------+
2 rows in set (0.00 sec)

mysql> CREATE TABLE publisher (
    -> pub_name VARCHAR(50) PRIMARY KEY,
    -> pub_addr VARCHAR(50)
    -> );
Query OK, 0 rows affected (0.02 sec)

mysql> DESC publisher;
+----------+-------------+------+-----+---------+-------+
| Field    | Type        | Null | Key | Default | Extra |
+----------+-------------+------+-----+---------+-------+
| pub_name | varchar(50) | NO   | PRI | NULL    |       |
| pub_addr | varchar(50) | YES  |     | NULL    |       |
+----------+-------------+------+-----+---------+-------+
2 rows in set (0.00 sec)

mysql> CREATE TABLE book (
    -> book_id INT PRIMARY KEY,
    -> title VARCHAR(50),
    -> auth_name VARCHAR(50),
    -> unit_price INT,
    -> pub_name VARCHAR(50),
    -> pub_year INT,
    -> 
    -> FOREIGN KEY (auth_name)
    -> REFERENCES author(auth_name),
    -> 
    -> FOREIGN KEY (pub_name)
    -> REFERENCES publisher(pub_name)
    -> );
Query OK, 0 rows affected (0.03 sec)

mysql> DESC book;
+------------+-------------+------+-----+---------+-------+
| Field      | Type        | Null | Key | Default | Extra |
+------------+-------------+------+-----+---------+-------+
| book_id    | int         | NO   | PRI | NULL    |       |
| title      | varchar(50) | YES  |     | NULL    |       |
| auth_name  | varchar(50) | YES  | MUL | NULL    |       |
| unit_price | int         | YES  |     | NULL    |       |
| pub_name   | varchar(50) | YES  | MUL | NULL    |       |
| pub_year   | int         | YES  |     | NULL    |       |
+------------+-------------+------+-----+---------+-------+
6 rows in set (0.00 sec)

mysql> CREATE TABLE sale (
    -> sale_id INT PRIMARY KEY,
    -> cust_id INT,
    -> book_id INT,
    -> order_date DATE,
    -> quantity INT,
    -> 
    -> FOREIGN KEY (cust_id)
    -> REFERENCES customer(cust_id),
    -> 
    -> FOREIGN KEY (book_id)
    -> REFERENCES book(book_id)
    -> );
Query OK, 0 rows affected (0.02 sec)

mysql> DESC sale;
+------------+------+------+-----+---------+-------+
| Field      | Type | Null | Key | Default | Extra |
+------------+------+------+-----+---------+-------+
| sale_id    | int  | NO   | PRI | NULL    |       |
| cust_id    | int  | YES  | MUL | NULL    |       |
| book_id    | int  | YES  | MUL | NULL    |       |
| order_date | date | YES  |     | NULL    |       |
| quantity   | int  | YES  |     | NULL    |       |
+------------+------+------+-----+---------+-------+
5 rows in set (0.00 sec)

mysql> INSERT INTO customer
    -> VALUES
    -> (100, 'hari', '12345'),
    -> (101, 'john', '23456'),
    -> (102, 'ali', '34567');
Query OK, 3 rows affected (0.01 sec)
Records: 3  Duplicates: 0  Warnings: 0

mysql> SELECT *
    -> FROM customer;
+---------+-----------+------------+
| cust_id | cust_name | cust_phone |
+---------+-----------+------------+
|     100 | hari      | 12345      |
|     101 | john      | 23456      |
|     102 | ali       | 34567      |
+---------+-----------+------------+
3 rows in set (0.00 sec)

mysql> INSERT INTO author
    -> VALUES
    -> ('Brown', 'US'),
    -> ('Forouzan', 'US'),
    -> ('Navathe', 'India'),
    -> ('Samantha', 'India'),
    -> ('Tanenbaum', 'US'),
    -> ('V Prasad', 'India');
Query OK, 6 rows affected (0.00 sec)
Records: 6  Duplicates: 0  Warnings: 0

mysql> SELECT *
    -> FROM author;
+-----------+---------+
| auth_name | country |
+-----------+---------+
| Brown     | US      |
| Forouzan  | US      |
| Navathe   | India   |
| Samantha  | India   |
| Tanenbaum | US      |
| V Prasad  | India   |
+-----------+---------+
6 rows in set (0.01 sec)

mysql> INSERT INTO publisher
    -> VALUES
    -> ('Pearson', 'London'),
    -> ('PHI', 'Delhi'),
    -> ('TMH', 'UP');
Query OK, 3 rows affected (0.00 sec)
Records: 3  Duplicates: 0  Warnings: 0

mysql> SELECT *
    -> FROM publisher;
+----------+----------+
| pub_name | pub_addr |
+----------+----------+
| Pearson  | London   |
| PHI      | Delhi    |
| TMH      | UP       |
+----------+----------+
3 rows in set (0.00 sec)

mysql> INSERT INTO book
    -> VALUES
    -> (2001, 'DS', 'Samantha', 500, 'PHI', 2020),
    -> (2002, 'CP', 'V Prasad', 300, 'TMH', 2019),
    -> (2003, 'DBMS', 'Navathe', 900, 'Pearson', 2018),
    -> (2004, 'DC', 'Forouzan', 700, 'TMH', 2021),
    -> (2005, 'CN', 'Tanenbaum', 800, 'Pearson', 2018),
    -> (2006, 'Python', 'Brown', 800, 'TMH', 2021);
Query OK, 6 rows affected (0.00 sec)
Records: 6  Duplicates: 0  Warnings: 0

mysql> SELECT *
    -> FROM book;
+---------+--------+-----------+------------+----------+----------+
| book_id | title  | auth_name | unit_price | pub_name | pub_year |
+---------+--------+-----------+------------+----------+----------+
|    2001 | DS     | Samantha  |        500 | PHI      |     2020 |
|    2002 | CP     | V Prasad  |        300 | TMH      |     2019 |
|    2003 | DBMS   | Navathe   |        900 | Pearson  |     2018 |
|    2004 | DC     | Forouzan  |        700 | TMH      |     2021 |
|    2005 | CN     | Tanenbaum |        800 | Pearson  |     2018 |
|    2006 | Python | Brown     |        800 | TMH      |     2021 |
+---------+--------+-----------+------------+----------+----------+
6 rows in set (0.00 sec)

mysql> INSERT INTO sale 
    -> VALUES
    -> (301, 100, 2001, '2021-01-02', 3), 
    -> (302, 100, 2002, '2019-04-02', 4), 
    -> (303, 100, 2003, '2019-04-02', 2), 
    -> (304, 101, 2002, '2021-05-02', 2), 
    -> (305, 101, 2005, '2021-05-02', 1),
    -> (306, 102, 2006, '2022-01-02', 2);
Query OK, 6 rows affected (0.01 sec)
Records: 6  Duplicates: 0  Warnings: 0

mysql> SELECT *
    -> FROM sale;
+---------+---------+---------+------------+----------+
| sale_id | cust_id | book_id | order_date | quantity |
+---------+---------+---------+------------+----------+
|     301 |     100 |    2001 | 2021-01-02 |        3 |
|     302 |     100 |    2002 | 2019-04-02 |        4 |
|     303 |     100 |    2003 | 2019-04-02 |        2 |
|     304 |     101 |    2002 | 2021-05-02 |        2 |
|     305 |     101 |    2005 | 2021-05-02 |        1 |
|     306 |     102 |    2006 | 2022-01-02 |        2 |
+---------+---------+---------+------------+----------+
6 rows in set (0.00 sec)

mysql> SELECT SUM(b.unit_price * s.quantity) AS total_sales_2021_22
    -> FROM sale s
    -> JOIN book b ON s.book_id = b.book_id
    -> WHERE s.order_date BETWEEN '2021-04-01' AND '2022-03-31';
+---------------------+
| total_sales_2021_22 |
+---------------------+
|                3000 |
+---------------------+
1 row in set (0.01 sec)

mysql> SELECT
    -> pub_name,
    -> SUM(unit_price) AS total_price
    -> FROM book
    -> WHERE pub_name != 'PHI'
    -> GROUP BY pub_name;
+----------+-------------+
| pub_name | total_price |
+----------+-------------+
| Pearson  |        1700 |
| TMH      |        1800 |
+----------+-------------+
2 rows in set (0.00 sec)
 
mysql> SELECT 
    -> pub_name,
    -> SUM(unit_price) AS total_price
    -> FROM book
    -> GROUP BY pub_name;
+----------+-------------+
| pub_name | total_price |
+----------+-------------+
| Pearson  |        1700 |
| PHI      |         500 |
| TMH      |        1800 |
+----------+-------------+
3 rows in set (0.00 sec)

mysql> SELECT
    -> c.cust_name,
    -> b.title
    -> FROM sale s
    -> JOIN customer c ON s.cust_id = c.cust_id
    -> JOIN book b ON s.book_id = b.book_id;
+-----------+--------+
| cust_name | title  |
+-----------+--------+
| hari      | DS     |
| hari      | CP     |
| hari      | DBMS   |
| john      | CP     |
| john      | CN     |
| ali       | Python |
+-----------+--------+
6 rows in set (0.00 sec)

mysql> SELECT
    -> b.title,
    -> a.auth_name,
    -> a.country
    -> FROM book b
    -> JOIN author a ON b.auth_name = a.auth_name
    -> WHERE b.pub_year = 2021;
+--------+-----------+---------+
| title  | auth_name | country |
+--------+-----------+---------+
| DC     | Forouzan  | US      |
| Python | Brown     | US      |
+--------+-----------+---------+
2 rows in set (0.00 sec)

mysql> SELECT
    -> b.title,
    -> a.auth_name
    -> FROM book b
    -> JOIN author a ON b.auth_name = a.auth_name
    -> WHERE a.country != 'India';
+--------+-----------+
| title  | auth_name |
+--------+-----------+
| Python | Brown     |
| DC     | Forouzan  |
| CN     | Tanenbaum |
+--------+-----------+
3 rows in set (0.00 sec)

mysql> SELECT
    -> cust_id,
    -> SUM(quantity) AS total_quantity
    -> FROM sale
    -> GROUP BY cust_id
    -> ORDER BY total_quantity DESC;
+---------+----------------+
| cust_id | total_quantity |
+---------+----------------+
|     100 |              9 |
|     101 |              3 |
|     102 |              2 |
+---------+----------------+
3 rows in set (0.00 sec)