CREATE TABLE employee (
    empNo INT PRIMARY KEY, 
    empName VARCHAR(25),
    empAddress VARCHAR(50),
    salary INT, dept VARCHAR(20)
);

DESC employee;

INSERT INTO employee
VALUES 
    (2001, 'Hari', 'Palakkad', 30000, 'Reasearch'),
    (2002, 'Devi', 'Kasaragod', 40000, 'Network'), 
    (2003, 'Gupta', 'Kannur', 50000, 'System Admin'),
    (2004, 'Ravi', 'Calicut', 60000, 'HR'),
    (2005, 'Rani', 'Calicut', 70000, 'HR');

SELECT *
FROM employee;

SELECT SUM(salary)
FROM employee;

SELECT COUNT(salary)
FROM employee
WHERE salary < 50000;

SELECT *
FROM employee
WHERE salary = (
    SELECT MAX(salary)
    FROM employee
);

ALTER TABLE employee 
ADD column (title VARCHAR(25) DEFAULT ('junior software engineer'));

SELECT *
FROM employee;

UPDATE employee
SET title = 'senior software engineer'
WHERE empNo = 2004;

SELECT *
FROM employee;

DELETE
FROM employee
WHERE empNo = 2005;

SELECT *
FROM employee;