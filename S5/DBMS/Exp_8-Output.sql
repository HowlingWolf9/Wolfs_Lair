mysql> CREATE TABLE Item(
    -> item_id INT PRIMARY KEY,
    -> item_desc VARCHAR(50),
    -> qty_on_hand INT,
    -> unit_price INT,
    -> category VARCHAR(50)
    -> );
Query OK, 0 rows affected (0.48 sec)

mysql> DESC Item;
+-------------+-------------+------+-----+---------+-------+
| Field       | Type        | Null | Key | Default | Extra |
+-------------+-------------+------+-----+---------+-------+
| item_id     | int         | NO   | PRI | NULL    |       |
| item_desc   | varchar(50) | YES  |     | NULL    |       |
| qty_on_hand | int         | YES  |     | NULL    |       |
| unit_price  | int         | YES  |     | NULL    |       |
| category    | varchar(50) | YES  |     | NULL    |       |
+-------------+-------------+------+-----+---------+-------+
5 rows in set (0.00 sec)

mysql> CREATE TABLE Sales(
    -> sale_id INT PRIMARY KEY, 
    -> item_id INT, 
    -> qty_sold INT, 
    -> unit_price INT, 
    -> total_price INT, 
    -> tax_amount INT, 
    -> grand_total INT,
    -> 
    -> FOREIGN KEY (item_id)
    -> REFERENCES Item(item_id)
    -> );
Query OK, 0 rows affected (0.58 sec)

mysql> DESC Sales;
+-------------+------+------+-----+---------+-------+
| Field       | Type | Null | Key | Default | Extra |
+-------------+------+------+-----+---------+-------+
| sale_id     | int  | NO   | PRI | NULL    |       |
| item_id     | int  | YES  | MUL | NULL    |       |
| qty_sold    | int  | YES  |     | NULL    |       |
| unit_price  | int  | YES  |     | NULL    |       |
| total_price | int  | YES  |     | NULL    |       |
| tax_amount  | int  | YES  |     | NULL    |       |
| grand_total | int  | YES  |     | NULL    |       |
+-------------+------+------+-----+---------+-------+
7 rows in set (0.00 sec)

mysql> INSERT INTO Item VALUES
    -> (100, 'TextBook', 20, 20, 'book'), 
    -> (101, 'milkybar', 30, 5, 'chocolate'),
    -> (102, 'apple', 50, 10, 'fruit'),
    -> (103, 'pen', 100, 8, 'stationery');
Query OK, 4 rows affected (0.08 sec)
Records: 4  Duplicates: 0  Warnings: 0

mysql> SELECT * FROM Item;
+---------+-----------+-------------+------------+------------+
| item_id | item_desc | qty_on_hand | unit_price | category   |
+---------+-----------+-------------+------------+------------+
|     100 | TextBook  |          20 |         20 | book       |
|     101 | milkybar  |          30 |          5 | chocolate  |
|     102 | apple     |          50 |         10 | fruit      |
|     103 | pen       |         100 |          8 | stationery |
+---------+-----------+-------------+------------+------------+
4 rows in set (0.00 sec)

mysql> DELIMITER //
mysql> CREATE TRIGGER updateSalesTable
    -> BEFORE INSERT
    -> ON Sales
    -> FOR EACH ROW
    -> BEGIN
    -> 
    -> DECLARE temp_category VARCHAR(50) DEFAULT 'other';
    -> DECLARE temp_unit_price INT;
    -> 
    -> SELECT category, unit_price
    -> INTO temp_category, temp_unit_price
    -> FROM Item
    -> WHERE item_id = new.item_id;
    -> 
    -> SET new.unit_price = temp_unit_price;
    -> 
    -> SET new.total_price = new.unit_price * new.qty_sold;
    -> 
    -> IF temp_category = 'book' THEN
    -> SET new.tax_amount = new.total_price * 0.1;
    -> ELSEIF temp_category = 'stationery' THEN
    -> SET new.tax_amount = new.total_price * 0.2 ;
    -> ELSEIF temp_category = 'chocolate' THEN
    -> SET new.tax_amount = new.total_price * 0.3;
    -> ELSE 
    -> SET new.tax_amount = new.total_price * 0.05;
    -> END IF;
    -> 
    -> SET new.grand_total = new.total_price + new.tax_amount;
    -> 
    -> END //
Query OK, 0 rows affected (0.20 sec)

mysql> DELIMITER ;

mysql> CREATE TRIGGER updateItemsTable
    -> BEFORE INSERT
    -> ON Sales
    -> FOR EACH ROW
    -> UPDATE Item
    -> SET qty_on_hand = qty_on_hand - new.qty_sold
    -> WHERE item_id = new.item_id;
Query OK, 0 rows affected (0.12 sec)

mysql> INSERT INTO Sales(sale_id,item_id,qty_sold) 
    -> VALUES (200,100,10);
Query OK, 1 row affected (0.11 sec)

mysql> INSERT INTO Sales(sale_id,item_id,qty_sold) 
    -> VALUES (201,101,25);
Query OK, 1 row affected (0.08 sec)

mysql> INSERT INTO Sales(sale_id,item_id,qty_sold) 
    -> VALUES (202,102,10);
Query OK, 1 row affected (0.12 sec)

mysql> INSERT INTO Sales(sale_id,item_id,qty_sold) 
    -> VALUES(203,103,20);
Query OK, 1 row affected (0.18 sec)

mysql> SELECT * FROM Sales;
+---------+---------+----------+------------+-------------+------------+-------------+
| sale_id | item_id | qty_sold | unit_price | total_price | tax_amount | grand_total |
+---------+---------+----------+------------+-------------+------------+-------------+
|     200 |     100 |       10 |         20 |         200 |         20 |         220 |
|     201 |     101 |       25 |          5 |         125 |         38 |         163 |
|     202 |     102 |       10 |         10 |         100 |          5 |         105 |
|     203 |     103 |       20 |          8 |         160 |         32 |         192 |
+---------+---------+----------+------------+-------------+------------+-------------+
4 rows in set (0.00 sec)

mysql> SELECT * FROM Item;
+---------+-----------+-------------+------------+------------+
| item_id | item_desc | qty_on_hand | unit_price | category   |
+---------+-----------+-------------+------------+------------+
|     100 | TextBook  |          10 |         20 | book       |
|     101 | milkybar  |           5 |          5 | chocolate  |
|     102 | apple     |          40 |         10 | fruit      |
|     103 | pen       |          80 |          8 | stationery |
+---------+-----------+-------------+------------+------------+
4 rows in set (0.00 sec)
