CREATE TABLE emp (
    empId INT PRIMARY KEY,
    empName VARCHAR(100),
    deptNo INT,
    salary INT
);

DESC emp;

INSERT INTO emp
VALUES
    (2001, 'Hari', 1006, 30000),
    (2002, 'Devi', 1002, 40000),
    (2003, 'Gupta', 1003, 50000),
    (2004, 'Ravi', 1004, 60000),
    (2005, 'Rani', 1007, 70000),
    (2006, 'John', 1003, 40000);

SELECT *
FROM emp;
CREATE TABLE dept (
    deptNo INT PRIMARY KEY,
    deptName VARCHAR(100),
    deptLocation VARCHAR(100)
);

DESC dept;

INSERT INTO dept
VALUES
    (1001, 'HR', 'Calicut'),
    (1002, 'Marketing', 'Cochin'),
    (1003, 'Sales', 'Trivandrum'),
    (1004, 'Testing', 'Bangalore'),
    (1005, 'Development', 'Bangalore');

SELECT *
FROM dept;

SELECT 
    empName,
    deptName
FROM 
    emp e,
    dept d
WHERE e.deptNo = d.deptNo;

SELECT
    empId,
    empName,
    deptNo
FROM emp
WHERE deptNo 
NOT IN (
    SELECT deptNo
    FROM dept
);

SELECT deptNo
FROM emp
UNION
SELECT deptNo
FROM dept;

SELECT
    deptNo,
    deptName
FROM dept
WHERE deptNo 
NOT IN (
    SELECT deptNo
    FROM emp
);

SELECT 
    d.deptNo,
    e.empId,
    e.empName
FROM
    emp e,
    dept d
WHERE e.deptNo = d.deptNo
AND d.deptLocation = 'Cochin';

SELECT *
FROM emp
WHERE
    salary > (
        SELECT AVG(e.salary)
        FROM 
            emp e,
            dept d
        WHERE e.deptNo = d.deptNo
        AND d.deptName = 'Sales'
    );

SELECT empName
FROM emp
WHERE salary > (
    SELECT MAX(salary)
    FROM emp
    WHERE deptNo = 1003
);

UPDATE emp 
SET salary = 1.2 * salary
WHERE deptno = (
    SELECT deptno
    FROM dept 
    WHERE deptname = 'Sales'
);

SELECT
    empid,
    empName,
    salary,
    deptName
FROM
    emp e,
    dept d
WHERE e.deptno=d.deptno;

SELECT *
FROM emp;

SELECT e.empid
FROM emp e 
WHERE salary > (
    SELECT AVG(salary)
    FROM emp b 
    WHERE b.deptno=e.deptno
);

SELECT 
    deptno,
    COUNT(*)
FROM emp e
WHERE salary > 40000 
GROUP BY deptno 
HAVING (
    SELECT COUNT(*)
    FROM emp f 
    WHERE f.deptno = e.deptno
    ) > 1;