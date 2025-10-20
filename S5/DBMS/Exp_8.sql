CREATE TABLE Item (
	item_id INT PRIMARY KEY,
	item_desc VARCHAR(50),
	qty_on_hand INT,
	unit_price INT,
	category VARCHAR(50)
);

DESC Item;

CREATE TABLE Sales (
	sale_id INT PRIMARY KEY, 
	item_id INT, 
	qty_sold INT, 
	unit_price INT, 
	total_price INT, 
	tax_amount INT, 
	grand_total INT,
	
	FOREIGN KEY (item_id)
	REFERENCES Item(item_id)
);

DESC Sales;

INSERT INTO Item 
VALUES
	(100, 'TextBook', 20, 20, 'book'), 
	(101, 'milkybar', 30, 5, 'chocolate'),
	(102, 'apple', 50, 10, 'fruit'),
	(103, 'pen', 100, 8, 'stationery');
	
SELECT * 
FROM Item;

DELIMITER //
CREATE TRIGGER updateSalesTable
BEFORE INSERT
ON Sales
FOR EACH ROW
BEGIN

DECLARE temp_category VARCHAR(50) DEFAULT 'other';
DECLARE temp_unit_price INT;

SELECT category, unit_price
INTO temp_category, temp_unit_price
FROM Item
WHERE item_id = new.item_id;

SET new.unit_price = temp_unit_price;

SET new.total_price = new.unit_price * new.qty_sold;

IF temp_category = 'book' THEN
SET new.tax_amount = new.total_price * 0.1;
ELSEIF temp_category = 'stationery' THEN
SET new.tax_amount = new.total_price * 0.2 ;
ELSEIF temp_category = 'chocolate' THEN
SET new.tax_amount = new.total_price * 0.3;
ELSE 
SET new.tax_amount = new.total_price * 0.05;
END IF;

SET new.grand_total = new.total_price + new.tax_amount;

END //
DELIMITER ;

CREATE TRIGGER updateItemsTable
BEFORE INSERT
ON Sales
FOR EACH ROW
UPDATE Item
SET qty_on_hand = qty_on_hand - new.qty_sold
WHERE item_id = new.item_id;

INSERT INTO Sales(sale_id,item_id,qty_sold) 
VALUES (200,100,10);

INSERT INTO Sales(sale_id,item_id,qty_sold) 
VALUES (201,101,25);

INSERT INTO Sales(sale_id,item_id,qty_sold) 
VALUES (202,102,10);

INSERT INTO Sales(sale_id,item_id,qty_sold) 
VALUES(203,103,20);

SELECT * FROM Sales;

SELECT * FROM Item;
