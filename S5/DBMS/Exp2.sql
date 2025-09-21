CREATE TABLE student (
    studentNo INT PRIMARY KEY,
    studentName VARCHAR(50),
    maths INT, 
    physics INT, 
    chemistry INT, 
    cProgramming INT, 
    department VARCHAR(10),
    address VARCHAR(50)
);

DESC student;

INSERT INTO student
VALUES 
    (100, 'Hari', 50, 60, 45, 75, 'CSE', 'Kasaragod'),
    (101, 'Devi', 60, 55, 78, 40, 'CSE', 'Kasaragod'),
    (102, 'Sam', 45, 77, 88, 45, 'IT', 'Kannur'),
    (103, 'Sreehari', 90, 75, 77, 60, 'IT', 'Calicut'),
    (104, 'Rani', 91, 98, 89, 52, 'ECE', 'Kannur'),
    (105, 'Raj', 88, 77, 67, 48, 'CSE', 'Palakkad');

SELECT *
FROM student;

SELECT 
    studentNo,
    studentName
FROM student
WHERE cProgramming < 50
ORDER BY cProgramming ASC;

SELECT 
    studentNo,
    studentName,
    department
FROM student
ORDER BY 
    department DESC,
    studentName ASC;

SELECT studentName
FROM student
WHERE studentName LIKE 'S%';

SELECT studentName
FROM student
ORDER BY cProgramming DESC
LIMIT 1
OFFSET 1;

SELECT 
    department,
    COUNT(department) AS student_count,
    AVG(maths) AS avg_maths_score
FROM student
GROUP BY department;

SELECT COUNT(studentNo) AS student_count
FROM student
WHERE physics BETWEEN 70 AND 80;

ALTER TABLE student 
DROP PRIMARY KEY;

DESC student;

ALTER TABLE student 
ADD PRIMARY KEY (studentNo, studentName);

DESC student;

INSERT INTO student
VALUES (100, 'Sam', 100, 100, 100, 0, 'CSE', 'Thrissur');
SELECT *
FROM student;