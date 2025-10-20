CREATE TABLE customer (
	cust_id INT PRIMARY KEY,
	cust_name VARCHAR(50),
	cust_phone VARCHAR(5)
);

DESC customer;

CREATE TABLE author (
	auth_name VARCHAR(50) PRIMARY KEY,
	country VARCHAR(50)
);

DESC author;

CREATE TABLE publisher (
	pub_name VARCHAR(50) PRIMARY KEY,
	pub_addr VARCHAR(50)
);

DESC publisher;

CREATE TABLE book (
	book_id INT PRIMARY KEY,
	title VARCHAR(50),
	auth_name VARCHAR(50),
	unit_price INT,
	pub_name VARCHAR(50),
	pub_year INT,
	
	FOREIGN KEY (auth_name)
	REFERENCES author(auth_name),
	
	FOREIGN KEY (pub_name)
	REFERENCES publisher(pub_name)
);

DESC book;

CREATE TABLE sale (
	sale_id INT PRIMARY KEY,
	cust_id INT,
	book_id INT,
	order_date DATE,
	quantity INT,
	
	FOREIGN KEY (cust_id)
	REFERENCES customer(cust_id),
	
	FOREIGN KEY (book_id)
	REFERENCES book(book_id)
);

DESC sale;

INSERT INTO customer
VALUES
	(100, 'hari', '12345'),
	(101, 'john', '23456'),
	(102, 'ali', '34567');

SELECT *
FROM customer;

INSERT INTO author
VALUES
	('Brown', 'US'),
	('Forouzan', 'US'),
	('Navathe', 'India'),
	('Samantha', 'India'),
	('Tanenbaum', 'US'),
	('V Prasad', 'India');

SELECT *
FROM author;

INSERT INTO publisher
VALUES
	('Pearson', 'London'),
	('PHI', 'Delhi'),
	('TMH', 'UP');

SELECT *
FROM publisher;

INSERT INTO book
VALUES
	(2001, 'DS', 'Samantha', 500, 'PHI', 2020),
	(2002, 'CP', 'V Prasad', 300, 'TMH', 2019),
	(2003, 'DBMS', 'Navathe', 900, 'Pearson', 2018),
	(2004, 'DC', 'Forouzan', 700, 'TMH', 2021),
	(2005, 'CN', 'Tanenbaum', 800, 'Pearson', 2018),
	(2006, 'Python', 'Brown', 800, 'TMH', 2021);

SELECT *
FROM book;

INSERT INTO sale 
VALUES
	(301, 100, 2001, '2021-01-02', 3), 
	(302, 100, 2002, '2019-04-02', 4), 
	(303, 100, 2003, '2019-04-02', 2), 
	(304, 101, 2002, '2021-05-02', 2), 
	(305, 101, 2005, '2021-05-02', 1),
	(306, 102, 2006, '2022-01-02', 2);

SELECT *
FROM sale;

SELECT SUM(b.unit_price * s.quantity) AS total_sales_2021_22
FROM sale s
JOIN book b ON s.book_id = b.book_id
WHERE s.order_date BETWEEN '2021-04-01' AND '2022-03-31';

SELECT
	pub_name,
	SUM(unit_price) AS total_price
FROM book
WHERE pub_name != 'PHI'
GROUP BY pub_name;

SELECT 
	pub_name,
	SUM(unit_price) AS total_price
FROM book
GROUP BY pub_name;

SELECT
	c.cust_name,
	b.title
FROM sale s
JOIN customer c ON s.cust_id = c.cust_id
JOIN book b ON s.book_id = b.book_id;

SELECT
	b.title,
	a.auth_name,
	a.country
FROM book b
JOIN author a ON b.auth_name = a.auth_name
WHERE b.pub_year = 2021;

SELECT
	b.title,
	a.auth_name
FROM book b
JOIN author a ON b.auth_name = a.auth_name
WHERE a.country != 'India';

SELECT
	cust_id,
	SUM(quantity) AS total_quantity
FROM sale
GROUP BY cust_id
ORDER BY total_quantity DESC;