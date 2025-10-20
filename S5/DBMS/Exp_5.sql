CREATE VIEW student_info AS
SELECT 
    studentNo,
    studentName,
    department,
    address
FROM student;

SELECT * FROM student_info;

CREATE VIEW student_mark AS
SELECT 
    studentNo,
    studentName,
    maths,
    physics,
    chemistry,
    cProgramming
FROM student;

SELECT * FROM student_mark;

SELECT 
    sm.studentNo,
    sm.studentName,
    (sm.maths + sm.physics + sm.chemistry + sm.cProgramming) AS totalMarks,
    si.address
FROM student_mark sm
JOIN student_info si ON sm.studentNo = si.studentNo;

CREATE VIEW emp_dept AS
SELECT e.empName, d.deptName
FROM emp e
LEFT JOIN dept d ON e.deptNo = d.deptNo;
SELECT * FROM emp_dept;

SELECT empName
FROM emp_dept
WHERE deptName IS NULL;