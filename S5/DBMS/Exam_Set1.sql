CREATE TABLE Students (
    studentId INT PRIMARY KEY,
    studentName VARCHAR(50),
    creditsCompleted INT
);

CREATE TABLE Courses (
    courseId INT PRIMARY KEY,
    courseName VARCHAR(50),
    credits INT
);

CREATE TABLE Enrollments (
    enrollmentId INT PRIMARY KEY AUTO_INCREMENT,
    studentId INT,
    courseId INT,
    grade ENUM('A', 'B', 'C', 'F'),

    FOREIGN KEY (studentId)
    REFERENCES Students(studentId),

    FOREIGN KEY (courseId)
    REFERENCES Courses(courseId)
);

DROP PROCEDURE IF EXISTS EnrollStudent;
DELIMITER //
CREATE PROCEDURE EnrollStudent(IN s_id INT, IN c_id INT)
BEGIN
    DECLARE temp INT;

    SELECT courseId
    INTO temp
    FROM Enrollments
    WHERE studentId = s_id AND courseId = c_id; 

    IF (c_id = temp) THEN
        SIGNAL SQLSTATE '45001'
            SET MESSAGE_TEXT = 'Student is already enrolled in this course';
    ELSE
        INSERT INTO Enrollments (studentId, courseId)
        VALUES (
            s_id,
            c_id
        );
    END IF;
END //
DELIMITER ;

DROP TRIGGER IF EXISTS UpdateCreditsOnGrade;
DELIMITER //
CREATE TRIGGER UpdateCreditsOnGrade
AFTER UPDATE
ON Enrollments FOR EACH ROW
BEGIN
    DECLARE temp_credits INT;
    
    SELECT credits
    INTO temp_credits
    FROM Courses
    WHERE courseId = NEW.courseId;

    IF OLD.grade IS NULL AND NEW.grade IN ('A', 'B', 'C') THEN
        UPDATE Students
        SET creditsCompleted = creditsCompleted + temp_credits
        WHERE studentId = NEW.studentId;
    END IF;
END //
DELIMITER ;

DROP FUNCTION IF EXISTS GetTotalEnrollments;
DELIMITER //
CREATE FUNCTION GetTotalEnrollments(s_id INT)
RETURNS INT
DETERMINISTIC
BEGIN
    DECLARE totalEnrollments INT;

    SELECT COUNT(*)
    INTO totalEnrollments
    FROM Enrollments
    WHERE studentId = s_id AND grade IS NULL;

    RETURN totalEnrollments;
END //
DELIMITER ;


