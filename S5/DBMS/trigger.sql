CREATE TABLE table1(
	var1 INT(3) NOT NULL,
	var2 INT(3) NOT NULL,
	sum INT(3) NULL
);

CREATE TRIGGER updateSumTable1
BEFORE INSERT
ON table1
FOR EACH ROW
SET new.sum=new.var1+new.var2;

INSERT INTO table1 VALUES(3,6,NULL);

CREATE TABLE table2(
	var1 INT(3) NOT NULL,
	var2 INT(3) NOT NULL,
	sum INT(3) NULL
);

CREATE TRIGGER updateTable2
AFTER DELETE
ON table1
FOR EACH ROW
INSERT INTO table2 VALUES(old.var1,old.var2,old.sum);

DELETE FROM table1 WHERE var1=3;

CREATE TABLE table3(
var INT NOT NULL,
sum INT NULL
);

DELIMITER //
CREATE TRIGGER updateSumTable3
BEFORE UPDATE
ON table3
FOR EACH ROW
BEGIN
IF(new.var>old.var) THEN
SET new.sum=old.sum+new.var;
END IF;
END //

DELIMITER ;

INSERT INTO table3 VALUES(3,3);

UPDATE table3 SET var=5 WHERE var=3;

UPDATE table3 SET var=2 WHERE var=5;
